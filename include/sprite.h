#ifndef UGINE_SPRITE_H
#define UGINE_SPRITE_H

#include "renderer.h"
#include "types.h"

class Collision;
class CollisionPixelData;
class Image;
class Map;

class Sprite {
public:
	enum CollisionMode {
		COLLISION_NONE,
		COLLISION_CIRCLE,
		COLLISION_PIXEL,
		COLLISION_RECT
	};

	Sprite(Image* image);
	virtual ~Sprite();

    virtual void SetImage(Image* image) 
    { 
    /* TAREA: Implementar */ 
        this->image = image;
    }
    virtual const Image* GetImage() const 
    { 
        return image;
    }

    virtual void SetPosition(double x, double y, double z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;

     /*   printf("SetX X %f \n", x);

        printf("SetPosition X %f \n", this->x);
        printf("SetPosition Y %f \n", this->y);*/
    }

    virtual void SetX(double x) { this->x = x; }
    virtual void SetY(double y) { this->y = y; }
    virtual void SetZ(double z) { this->z = z; }
    virtual double GetX() const 
    {
        //printf("getx X %f \n", this->x);
        return x;
    }
    virtual double GetY() const { return y; }
    virtual double GetZ() const { return z; }
	//Despues se utilizara
	virtual double GetScreenX() const { return x; }
	virtual double GetScreenY() const { return y; }

	virtual void SetAngle(double angle) { this->angle = angle; }
	virtual double GetAngle() const { return angle; }

	virtual void SetScale(double sx, double sy) { scalex = sx; scaley = sy; }
	virtual void SetScaleX(double sx) { scalex = sx; }
	virtual void SetScaleY(double sy) { scaley = sy; }
	virtual double GetScaleX() const { return scalex; }
	virtual double GetScaleY() const { return scaley; }

    virtual void SetFPS(int16 fps) { this->animFPS = fps; }
    virtual int16 GetFPS() const { return animFPS; }
    virtual void SetFrameRange(uint16 firstFrame, uint16 lastFrame) { this->firstFrame = firstFrame; this->lastFrame = lastFrame; }
    virtual uint16 GetFirstFrame() const { return firstFrame; }
    virtual uint16 GetLastFrame() { return lastFrame; }
    virtual void SetCurrentFrame(uint16 frame) { this->currentFrame = frame; }
    virtual uint16 GetCurrentFrame() const { return currentFrame; }

    virtual void SetBlendMode(Renderer::BlendMode blend)
    {
        this->blendMode = blend;
        Renderer::Instance().SetBlendMode(blend);
    }
    virtual Renderer::BlendMode GetBlendMode() const 
    { 
        return blendMode;
    }
    virtual void SetColor(uint8 r, uint8 g, uint8 b, uint8 alpha = 255)
    {
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = alpha;
    }

    virtual uint8 GetRed() const { return r;}
    virtual uint8 GetGreen() const { return g; }
    virtual uint8 GetBlue() const { return b; }
    virtual uint8 GetAlpha() const { return a; }

//    virtual void SetRadius(double radius) { /* TAREA: Implementar */ }
//    virtual double GetRadius() const { /* TAREA: Implementar */ }

	virtual void SetCollision(CollisionMode mode);
    virtual void SetCollisionPixelData(const CollisionPixelData* colPixelData) { /* TAREA: Implementar */ }
//    virtual const Collision* GetCollision() const { /* TAREA: Implementar */ }
    virtual bool CheckCollision(Sprite* sprite);
    virtual bool CheckCollision(const Map* map);
//    virtual const Sprite* CollisionSprite() const { /* TAREA: Implementar */ }
//    virtual bool DidCollide() const { /* TAREA: Implementar */ }

    virtual void RotateTo(int32 angle, double speed);
    virtual void MoveTo(double x, double y, double speedX, double speedY = 0.0);
	virtual bool IsRotating() const { return rotating; }
	virtual bool IsMoving() const { return moving; }

    virtual void Update(double elapsed, const Map* map = NULL);
    virtual void Render() const;
	
	virtual void SetUserData(void* data) { userData = data; }
	virtual void* GetUserData() { return userData; }
	virtual const void* GetUserData() const { return userData; }
protected:
    virtual void UpdateCollisionBox();
    virtual void UpdateCollisionBox(double x, double y, double w, double h);
private:
    Image* image;
    double x, y, z;
    double colx, coly, colwidth, colheight;
    double angle;
    double scalex, scaley;
    double radius;

    int16 animFPS;
    uint16 firstFrame, lastFrame;
    double currentFrame;

    Renderer::BlendMode blendMode;
    uint8 r, g, b, a;
    Collision* collision;
    const CollisionPixelData* colPixelData;
    Sprite* colSprite;
    bool collided;

    bool rotating;
    uint16 toAngle;
    double rotatingSpeed;
    //grados que quedan para llegar al angulo deseado
    double anglesToRotate;

    bool moving;
    double toX, toY;
    double movingSpeedX, movingSpeedY;
    double prevX, prevY;
	
	void* userData;
};

#endif
