#include "Level0.h"
#define LEVEL0_WIDTH 14
#define LEVEL0_HEIGHT 8

#define LEVEL0_ENEMY_COUNT 8
unsigned int level0_data[] =
{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

void Level0::Initialize() {
    state.nextScene = -1;
    
    GLuint mapTextureID = Util::LoadTexture("font1.png");
    state.map = new Map(LEVEL0_WIDTH, LEVEL0_HEIGHT, level0_data, mapTextureID, 1.0f, 16, 16);
    state.player = new Entity();
    state.player1 = new Entity();
    /*state.player->entityType = PLAYER;
    state.player->position = glm::vec3(5, 0, 0);
    state.player->movement = glm::vec3(0);
    state.player->acceleration = glm::vec3(0, -9.81f, 0);
    state.player->speed = 2.0f;
    state.player->textureID = Util::LoadTexture("george_0.png");
    
    state.player->animRight = new int[4] {3, 7, 11, 15};
    state.player->animLeft = new int[4] {1, 5, 9, 13};
    state.player->animUp = new int[4] {2, 6, 10, 14};
    state.player->animDown = new int[4] {0, 4, 8, 12};
    
    state.player->animIndices = state.player->animRight;
    state.player->animFrames = 4;
    state.player->animIndex = 0;
    state.player->animTime = 0;
    state.player->animCols = 4;
    state.player->animRows = 4;
    state.player->height = 0.8f;
    state.player->width = 0.8f;
    
    state.player->jumpPower = 6.0f;
    state.player->isActive = false;*/
    
    state.enemies = new Entity[LEVEL0_ENEMY_COUNT];
    /*GLuint enemyTextureID = Util::LoadTexture("enemy2.png");
    
    state.enemies[0].entityType = ENEMY;
    state.enemies[0].aiType = WAITANDGO;
    state.enemies[0].aiState = IDLE;
    state.enemies[0].textureID = enemyTextureID;
    state.enemies[0].position = glm::vec3(4, -2.25, 0);
    state.enemies[0].speed = 1;
    state.enemies[0].isActive = false;*/
}
void Level0::Update(float deltaTime) {
    /*state.player->Update(deltaTime, state.player, state.enemies, LEVEL0_ENEMY_COUNT, state.map);*/
}

void Level0::Render(ShaderProgram *program) {
    GLuint fontTextureID = Util::LoadTexture("font1.png");
    Util::DrawText(program, fontTextureID, "Space", 1, 0.01, glm::vec3(3, -1, 0));
    Util::DrawText(program, fontTextureID, "Race", 1, 0.01, glm::vec3(3.5, -2, 0));
    Util::DrawText(program, fontTextureID, "----------", 1, 0.01, glm::vec3(0, -3, 0));
    Util::DrawText(program, fontTextureID, "Press", 1, 0.01, glm::vec3(3, -4, 0));
    Util::DrawText(program, fontTextureID, "Enter To", 1, 0.01, glm::vec3(2, -5, 0));
    Util::DrawText(program, fontTextureID, "Start", 1, 0.01, glm::vec3(3, -6, 0));
    state.map->Render(program);
    //state.player->Render(program);
}
