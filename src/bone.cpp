#include "../include/bone.h"
#include "../include/glinclude.h"
#include "../include/image.h"
#include "../include/math.h"
#include "../include/renderer.h"

Bone::Bone() {
    this->id = "id";
    this->image = NULL;
    this->pivotX = 0;
    this->pivotY = 0;
    this->handleX = 0;
    this->handleY = 0;
    //currentX = currentY = 1;
    //currentRotation = 0;
    currentX = currentY = currentRotation = 0;
    currentScaleX = currentScaleY = 1;
}

Bone::Bone(const String& id, Image* image, double pivotX, double pivotY, double handleX, double handleY) {
    this->id = id;
	this->image = image;
	this->pivotX = pivotX;
	this->pivotY = pivotY;
	this->handleX = handleX;
	this->handleY = handleY;
   // currentX = currentY = 1;
   // currentRotation = 0;
	currentX = currentY = currentRotation = 0;
    currentScaleX = currentScaleY = 1;
}

const Bone* Bone::FindChild(const String &id) const {
    // Buscamos en los hijos del hueso
    for ( uint32 i = 0; i < children.Size(); i++ )
        if ( children[i].GetID() == id )
            return &children[i];

	// Si no, en toda su descendencia
    for ( uint32 i = 0; i < children.Size(); i++ ) {
        const Bone* bone = children[i].FindChild(id);
		if ( bone != NULL )
			return bone;
	}

	// No se ha encontrado
    return NULL;
}

Bone* Bone::FindChild(const String &id) {
    // Buscamos en los hijos del hueso
    for ( uint32 i = 0; i < children.Size(); i++ )
        if ( children[i].GetID() == id )
            return &children[i];

    // Si no, en toda su descendencia
    for ( uint32 i = 0; i < children.Size(); i++ ) {
        Bone* bone = children[i].FindChild(id);
        if ( bone != NULL )
            return bone;
    }

    // No se ha encontrado
    return NULL;
}

const Frame* Bone::FindFrame(uint32 id) const {
    for ( uint32 i = 0; i < frames.Size(); i++ )
        if ( frames[i].GetId() == id )
            return &frames[i];
	return NULL;
}

void Bone::TranslationForFrame(int32 f, double* x, double* y) const {
    const Frame* frame = NULL, * prevFrame = NULL, * nextFrame = NULL;
	GetFrame(f, &frame, &prevFrame, &nextFrame);

	if ( frame != NULL ) {
		*x = frame->GetTranslationX();
		*y = frame->GetTranslationY();
	} else if ( prevFrame != NULL  &&  nextFrame != NULL ) {
		*x = Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetTranslationX(), nextFrame->GetTranslationX());
		*y = Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetTranslationY(), nextFrame->GetTranslationY());
	} else {
		*x = *y = 0;
	}
}

double Bone::RotationForFrame(int32 f) const {
    const Frame* frame = NULL, * prevFrame = NULL, * nextFrame = NULL;
	GetFrame(f, &frame, &prevFrame, &nextFrame);

	if ( frame != NULL )
		return frame->GetRotation();
	else if ( prevFrame != NULL  &&  nextFrame != NULL )
		return WrapValue(Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetRotation(), nextFrame->GetRotation()), 360);
	else
		return 0;
}

void Bone::ScaleForFrame(int32 f, double* x, double* y) const {
    const Frame* frame = NULL, * prevFrame = NULL, * nextFrame = NULL;
	GetFrame(f, &frame, &prevFrame, &nextFrame);

	if ( frame != NULL ) {
		*x = frame->GetScaleX();
		*y = frame->GetScaleY();
	} else if ( prevFrame != NULL  &&  nextFrame != NULL ) {
		*x = Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetScaleX(), nextFrame->GetScaleX());
		*y = Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetScaleY(), nextFrame->GetScaleY());
	} else {
		*x = *y = 0;
	}
}

void Bone::Update(int32 currentFrame) {
	// TAREA: Implementar la especificacion del enunciado

    double tempCurrX = 0;
    double tempCurrY = 0;
    currentX = 0;
    currentY = 0;

    for (int x = 0; x <= currentFrame; x++)
    {
        tempCurrX = currentX;
        tempCurrY = currentY;
        TranslationForFrame(x, &currentX, &currentY);
        currentX += tempCurrX;
        currentY -= tempCurrY;
    }


    currentRotation = RotationForFrame(currentFrame);
    //ScaleForFrame(currentFrame, &currentScaleX, &currentScaleY);

    //for (uint32 i = 0; i < children.Size(); i++)
      //  children[i].Update(currentFrame);

    if (CountChildren() > 0)
    {
        GetChild(0)->Update(currentFrame);
    }
}

void Bone::Render() {
    // TAREA: Implementar la especificacion del enunciado

    Renderer::Instance().PushMatrix();
    
    //currentX = 10;
    Renderer::Instance().TranslateMatrix(currentX, currentY, 0);
    Renderer::Instance().RotateMatrix(currentRotation, 0, 0, -1);

    if (image != NULL)
    {
        //el huezo raiz gira sobre su eje sin desplazarse
        image->SetHandle(handleX*image->GetWidth(), handleY*image->GetHeight());
//        handleX = handleX*image->GetWidth();
  //      handleY = handleY*image->GetHeight();
        //double normalPivotY = WrapValue(pivotY, 1);
        Renderer::Instance().DrawImage(image, 0, 0, 0, image->GetWidth()*currentScaleX, image->GetHeight()*currentScaleY, currentRotation);

       // if (CountChildren() > 0)
         //   Renderer::Instance().TranslateMatrix(GetChild(0)->pivotX*image->GetWidth(), GetChild(0)->pivotY*image->GetHeight(), 0.0);
        double linkx = pivotX*image->GetWidth();
        double linky = pivotY*image->GetHeight();

        Renderer::Instance().TranslateMatrix(linkx, linky, 0.0);

    }

    //int numChildren = CountChildren();

    if (CountChildren() > 0)
    {
        GetChild(0)->Render();
    }

    Renderer::Instance().PopMatrix();

}

void Bone::GetFrame(int32 f, const Frame** frame, const Frame** prevFrame, const Frame** nextFrame) const {
	*frame = NULL;
	*prevFrame = NULL;
	*nextFrame = NULL;
    for ( uint32 i = 0; i < frames.Size(); i++ ) {
        if ( frames[i].GetId() == f )
            *frame = &frames[i];
        if ( frames[i].GetId() < f  &&  (*prevFrame == NULL  ||  (*prevFrame)->GetId() < frames[i].GetId()) )
            *prevFrame = &frames[i];
        if ( frames[i].GetId() > f  &&  (*nextFrame == NULL  ||  (*nextFrame)->GetId() > frames[i].GetId()) )
            *nextFrame = &frames[i];
	}
}

double Bone::Interpolate(int32 id, int32 prevId, int32 nextId, double prevVal, double nextVal) const {
	// TAREA: Implementar la especificacion del enunciado

    double idCast = static_cast<double>(id);
    double prevIdCast = static_cast<double>(prevId);
    double nextIdCast = static_cast<double>(nextId);
    double ipolValue = prevVal + (nextVal - prevVal) * ((idCast - prevIdCast) / (nextIdCast - prevIdCast));

    return ipolValue;
}

