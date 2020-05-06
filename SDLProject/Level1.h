#include "Scene.h"
#include <SDL_mixer.h>
class Level1 : public Scene {
public:
    Mix_Music *music;
    Mix_Chunk *fx;
    
    int winner = 0;
    
    void Initialize() override;
    void Update(float deltaTime) override;
    void Render(ShaderProgram *program) override;
};
