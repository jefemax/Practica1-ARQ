#include "../include/sprite.h"
//#include "../include/rectcollision.h"
#include "../include/image.h"
//#include "../include/map.h"
#include "../include/math.h"
//#include "../include/pixelcollision.h"
#include "../include/renderer.h"
//#include "../include/circlecollision.h"
#include <math.h>

Sprite::Sprite(Image* image) {
	// TAREA: Implementar
	this->image = image;
	x = y = z = 0;
    colx = coly = colwidth = colheight = 0;
	angle = 0;
	scalex = scaley = 1;
	double radius = 2;
	
	blendMode = Renderer::BlendMode::ALPHA;
	r = g = b = 255;
	a = 255;
	rotating = false;
    moving = false;

    userData = NULL;


}

Sprite::~Sprite() {
       delete userData;
}

void Sprite::SetCollision(CollisionMode mode) {
	// TAREA: Implementar
}

bool Sprite::CheckCollision(Sprite* sprite) {
	// TAREA: Implementar
	return false;
}

bool Sprite::CheckCollision(const Map* map) {
	// TAREA: Implementar
	return false;
}

void Sprite::RotateTo(int32 angle, double speed) {
    // TAREA: Implementar
    //Si esta rotando no hacer nada hasta que termine de rotar
    //Si el angulo de destino y el origen es el mismo  no hacer nada
        this->rotating = true;
        this->toAngle = angle;
        this->rotatingSpeed = speed;

        double ccw = WrapValue((this->toAngle - this->angle), 360);
        double cw = WrapValue((this->angle - this->toAngle), 360);

        if (ccw < cw)
        {
            this->anglesToRotate = ccw;
            this->rotatingSpeed = abs(speed);
        }
        else
        {
            this->anglesToRotate = cw;
            this->rotatingSpeed = -abs(speed);
        }
}

void Sprite::MoveTo(double x, double y, double speedX, double speedY) {
	// TAREA: Implementar
    if ((floor(x) != floor(this->x)) || y != this->y)
    {
        this->moving = true;
        this->toX = x;
        this->toY = y;
        if (speedY != 0)
        {
            movingSpeedX = speedX;
            movingSpeedY = speedY;
        }
        else
        {
            double distance = Distance(this->x, this->y, x, y);
            double time = distance / speedX;

            movingSpeedX = (x - this->x) / time;
            movingSpeedY = (y - this->y) / time;
        }
    }
    else
    {
        this->moving = false;
    }
}

void Sprite::Update(double elapsed, const Map* map) {
	// Informacion inicial de colision
	colSprite = NULL;
	collided = false;

	// TAREA: Actualizar animacion
    currentFrame += elapsed*GetFPS();
	if (currentFrame > lastFrame)
		currentFrame = firstFrame;

	if (currentFrame < firstFrame)
		currentFrame = lastFrame;

	// TAREA: Actualizar rotacion animada
    if (rotating && anglesToRotate > 0){
        //double angleCanRotate = WrapValue(elapsed*this->rotatingSpeed,360);
        double angleCanRotate = elapsed*this->rotatingSpeed;
        if (angleCanRotate > anglesToRotate)
        {
            angleCanRotate = anglesToRotate;
            this->angle += angleCanRotate;
            rotating = false;
        }
        else if (anglesToRotate > 0)
        {
            this->angle += angleCanRotate;
            anglesToRotate -= angleCanRotate;
        }
        else
            rotating = false;
    }
    // TAREA: Actualizar movimiento animado
    if (moving){

        x = x + movingSpeedX * elapsed;
        y = y + movingSpeedY * elapsed;
        if ((movingSpeedX < 0 && x <= toX) || (0 < movingSpeedX && toX <= x)){
            x = toX;
        }
        if ((movingSpeedY < 0 && y <= toY) || (0 < movingSpeedY && toY <= y)){
            y = toY;
        }
        if (x == toX && y == toY){
            moving = false;
        }
    }

	// Informacion final de colision
	UpdateCollisionBox();
}

void Sprite::Render() const {
    // TAREA: Implementar
    Renderer::Instance().SetBlendMode(GetBlendMode());
    Renderer::Instance().SetColor(GetRed(), GetGreen(), GetBlue(), GetAlpha());
	Renderer::Instance().DrawImage(image,x,y,currentFrame,image->GetWidth()*scalex,image->GetHeight()*scaley,angle);
}

void Sprite::UpdateCollisionBox() {
	// TAREA: Implementar
}

void Sprite::UpdateCollisionBox(double x, double y, double w, double h) {
	// TAREA: Implementar
}
