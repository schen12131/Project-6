#include "Level1.h"
#define LEVEL1_WIDTH 11
#define LEVEL1_HEIGHT 9

#define LEVEL1_ENEMY_COUNT 8
#define PLATFORM_COUNT 9

unsigned int level1_data[] =
{
    17, 61, 61, 61, 61, 61, 61, 61, 61, 61, 17,
    17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17,
    17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17,
    17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17,
    17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17,
    17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17,
    17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17,
    17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17,
    17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
};

void Level1::Initialize() {
    state.nextScene = -1;
    
    music = Mix_LoadMUS("crypto.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME/4);
    
    fx = Mix_LoadWAV("gameover.wav");
    
    GLuint mapTextureID = Util::LoadTexture("platformPack_tilesheet.png");
    state.map = new Map(LEVEL1_WIDTH, LEVEL1_HEIGHT, level1_data, mapTextureID, 1.0f, 14, 7);
    
    state.player = new Entity();
    state.player->entityType = PLAYER;
    state.player->position = glm::vec3(8, -7, 0);
    state.player->initialPos = glm::vec3(8, -7, 0);
    state.player->movement = glm::vec3(0);
    state.player->speed = 2.0f;
    state.player->textureID = Util::LoadTexture("rocket.png");
    state.player->points = 0;
    
    state.player1 = new Entity();
    state.player1->entityType = PLAYER;
    state.player1->position = glm::vec3(2, -7, 0);
    state.player1->initialPos = glm::vec3(2, -7, 0);
    state.player1->movement = glm::vec3(0);
    state.player1->speed = 2.0f;
    state.player1->textureID = Util::LoadTexture("rocket.png");
    state.player1->points = 0;
    
    
    state.enemies = new Entity[LEVEL1_ENEMY_COUNT];
    GLuint enemyTextureID = Util::LoadTexture("platformPack_tile012.png");
    
    
    state.enemies[0].entityType = ENEMY;
    state.enemies[0].aiType = FLOATING;
    state.enemies[0].movement = glm::vec3(-1, 0, 0);
    state.enemies[0].textureID = enemyTextureID;
    state.enemies[0].position = glm::vec3(rand() % 9 + 1, -6, 0);
    state.enemies[0].speed = ((float)rand()/RAND_MAX) + 0.3;
    
    state.enemies[1].entityType = ENEMY;
    state.enemies[1].aiType = FLOATING;
    state.enemies[1].movement = glm::vec3(-1, 1, 0);
    state.enemies[1].textureID = enemyTextureID;
    state.enemies[1].position = glm::vec3(rand() % 9 + 1, rand() % 7 - 7, 0);
    state.enemies[1].speed = ((float)rand()/RAND_MAX) + 0.3;
    
    state.enemies[2].entityType = ENEMY;
    state.enemies[2].aiType = FLOATING;
    state.enemies[2].movement = glm::vec3(1, -1, 0);
    state.enemies[2].textureID = enemyTextureID;
    state.enemies[2].position = glm::vec3(rand() % 9 + 1, rand() % 7 - 7, 0);
    state.enemies[2].speed = ((float)rand()/RAND_MAX) + 0.3;
    
    state.enemies[3].entityType = ENEMY;
    state.enemies[3].aiType = FLOATING;
    state.enemies[3].movement = glm::vec3(-1, -1, 0);
    state.enemies[3].textureID = enemyTextureID;
    state.enemies[3].position = glm::vec3(rand() % 9 + 1, rand() % 7 - 7, 0);
    state.enemies[3].speed = ((float)rand()/RAND_MAX) + 0.3;
    
    state.enemies[4].entityType = ENEMY;
    state.enemies[4].aiType = FLOATING;
    state.enemies[4].movement = glm::vec3(1, 1, 0);
    state.enemies[4].textureID = enemyTextureID;
    state.enemies[4].position = glm::vec3(rand() % 9 + 1, rand() % 7 - 7, 0);
    state.enemies[4].speed = ((float)rand()/RAND_MAX) + 0.3;
    
    state.enemies[5].entityType = ENEMY;
    state.enemies[5].aiType = FLOATING;
    state.enemies[5].movement = glm::vec3(-1, -1, 0);
    state.enemies[5].textureID = enemyTextureID;
    state.enemies[5].position = glm::vec3(rand() % 9 + 1, rand() % 7 - 7, 0);
    state.enemies[5].speed = ((float)rand()/RAND_MAX) + 0.3;
    
    state.enemies[6].entityType = ENEMY;
    state.enemies[6].aiType = FLOATING;
    state.enemies[6].movement = glm::vec3(-1, 1, 0);
    state.enemies[6].textureID = enemyTextureID;
    state.enemies[6].position = glm::vec3(rand() % 9 + 1, rand() % 7 - 7, 0);
    state.enemies[6].speed = ((float)rand()/RAND_MAX) + 0.3;
    
    state.enemies[7].entityType = ENEMY;
    state.enemies[7].aiType = FLOATING;
    state.enemies[7].movement = glm::vec3(-1, 0, 0);
    state.enemies[7].textureID = enemyTextureID;
    state.enemies[7].position = glm::vec3(rand() % 9 + 1, -3, 0);
    state.enemies[7].speed = ((float)rand()/RAND_MAX) + 0.3;
}
void Level1::Update(float deltaTime) {
    
    state.player->Update(deltaTime, state.player, state.enemies, LEVEL1_ENEMY_COUNT, state.map);
    state.player1->Update(deltaTime, state.player1, state.enemies, LEVEL1_ENEMY_COUNT, state.map);
    for (int i = 0; i < LEVEL1_ENEMY_COUNT; i ++){
        state.enemies[i].Update(deltaTime, state.player, NULL, 0, state.map);
        state.enemies[i].Update(deltaTime, state.player1, NULL, 0, state.map);
    }

    if (state.player->position.y >= -1.05){
        Mix_PlayChannel(-1, fx, 0);
    }
    
    if (state.player1->position.y >= -1.05){
        Mix_PlayChannel(-1, fx, 0);
    }
    
    if (state.player1->points == 20){
        winner = 1;
        state.player->isActive = false;
        state.player1->isActive = false;
    }
    if (state.player->points == 20){
        winner = 2;
        state.player->isActive = false;
        state.player1->isActive = false;
    }
}

void Level1::Render(ShaderProgram *program) {
    state.map->Render(program);
    state.player->Render(program);
    state.player1->Render(program);
    
    for (int i = 0; i < LEVEL1_ENEMY_COUNT; i ++){
        state.enemies[i].Render(program);
    }

    GLuint fontTextureID = Util::LoadTexture("font1.png");
    Util::DrawText(program, fontTextureID, std::to_string(state.player->points), 1, 0.1, glm::vec3(7, -7, 0));
    Util::DrawText(program, fontTextureID, std::to_string(state.player1->points), 1, 0.1, glm::vec3(3, -7, 0));
    
    if (winner == 1){
        Util::DrawText(program, fontTextureID, "Player 1 wins", 0.5, 0.1, glm::vec3(1.5, -3, 0));
    }
    if (winner == 2){
        Util::DrawText(program, fontTextureID, "Player 2 wins", 0.5, 0.1, glm::vec3(1.5, -3, 0));
    }
}
