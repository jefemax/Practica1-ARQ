#include "../include/image.h"
#include "../include/glinclude.h"
#include "../include/math.h"
#include "../include/stb_image.h"
#include "../include/renderer.h"
#include <math.h>
#include <stdlib.h>

// TAREA: Declarar funciones de stb_image.c

const int NUM_COMPS = 4;

Image::Image(const String &filename, uint16 hframes, uint16 vframes) {
	this->filename = filename;
    this->hframes = hframes;
    this->vframes = vframes;
	width = 0;
	height = 0;
	handlex = 0;
	handley = 0;
	gltex = 0;
	lastU = 1.0;
	lastV = 1.0;

	// TAREA: Cargar el buffer de la imagen
   
    int widthT = static_cast<int>(width);
    int heighT = static_cast<int>(height);
    int *numComp =0;

    stbi_uc *buffer = stbi_load(filename.ToCString(), &widthT, &heighT, numComp, 4);
    
	width = widthT;
	height = heighT;

    if (buffer == NULL)
        return;
    gltex = Renderer::Instance().GenImage(buffer, widthT, heighT);
    stbi_image_free(buffer);

    //Renderer::Instance().DrawRect(0, 290, 0, 0);

	// Generamos la textura
//	if ( buffer ) {
		// TAREA: Generar la textura de OpenGL
//	}
}

Image::~Image() {
	// TAREA: Eliminar la imagen de la memoria de OpenGL
    Renderer::Instance().DeleteImage(gltex);
}

void Image::Bind() const {
	// TAREA: Establecer la textura actual
    Renderer::Instance().BindImage(gltex);
}
