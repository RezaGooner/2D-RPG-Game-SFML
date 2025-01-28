#ifndef SFMLPROJECT_VALUECONFIG_H
#define SFMLPROJECT_VALUECONFIG_H

#define JUMPBLOCKY(num) (ground_level - ((num + 3) * platform_height))
#define JUMPBLOCKX(num) ((num - 1)  * platform_width)

#define POSY(num,height) (ground_level - (num * height))
#define POSX(num,width) (num * width)


// *************** WINDOW AND VIEW ***************
// MAP SIZE
const float  map_width = 2500.0f;
const float map_height =  600.0f;
// WINDOW SIZE AND TITLE
const int window_width   =     1200 ;
const int window_height  =      600 ;
sf::String window_title  = "Github.com/RezaGooner" ;
// VIEW SIZE
const int view_width  = 1200 ;
const int view_height = 600 ;
// SCORE BOARD
sf::String score_board_text = "Hi Player!\nScore >> 0\nArrow >> 0" ;
// score_board_new_text   GO TO LINE 68
const int score_board_text_size = 24 ;
sf::Color score_board_text_color(sf::Color::White);
sf::Color score_board_text_outline_color(sf::Color::Black);
const float score_board_text_outline_thickness = 1.5f ;

// *************** TIME AND FRAME ***************
// FRAME RATE LIMIT
const int frame_limit    =       60 ;
// TIME CHANGES VARIABLE
float delta_time ;
// DURATION OF EACH ANIMATION FRAME
float animation_duration = 0.1f;

// *************** COLOR ***************
const sf::Color orange_color(255,128,13);
const sf::Color green_color(57,255,20);
const sf::Color yellow_color(255,255,0);
const sf::Color red_color(255,0,0);
const sf::Color dark_red_color(139,0,0);
const sf::Color black_color(sf::Color::Black);
const sf::Color gray_color(50, 50, 50);


// *************** CHARACTER ***************
bool is_right = true ; // is character walking to right
// HEALTH
const float max_health =     100.0f;
float   current_health = max_health;
// GUN
bool    is_gun = false ; // is character have gun
int  arrow_num =     0 ; // number of arrow
// POSITION
const float character_first_position_x = 100.0f ;
const float character_first_position_y = 450.0f ;
// MOVEMENT
const float character_speed = 200.0f ;
// SIZE
const sf::Vector2i character_sprite_size(32, 32);
// ANIMATE
int character_animation_frame = 0;
const int character_animation_frame_num = 8 ;
// SCORE
int score = 0 ;
// GO TO LINE 24
sf::String score_board_new_text =
        "Hi Player!\nScore >> " + std::to_string(score) + "\nArrow >> " + std::to_string(arrow_num) ;

// *************** PHYSIC ***************
float velocity_y         =    0.0f;
float gravity            =   0.05f;
float jump_force         =  -3.75f;
bool  is_jumping         =   false;
bool  is_on_ground       =    true;
bool  is_jump_released   =    true;
const float ground_level =  450.0f;

// *************** GUN ***************
// STRUCT
struct Bullet {
    sf::Sprite shape;  // arrow shape, to right or left
    float      speed;
    int    direction;    // 1 = right , -1 = left
};
// SPEED
const float     bullet_speed =  500.0f ;
// DAMAGE
const int      bullet_damage =      20 ; // when character collides with the skeleton
// POSITION
std::vector<sf::Vector2f> bow_positions = {
        sf::Vector2f(45, ground_level - 32),
        sf::Vector2f(565, ground_level - 32)
};
// CHARGE
const int arrow_charge = 7 ;

// *************** ENEMY ***************
// STRUCT
struct Enemy {
    sf::Sprite                        sprite;
    float                              speed;
    int                               health;
    bool                              active;  // is in view
    int                            direction;  // plus = right , minus = left
    float                    animation_timer;  // total animation time
    int                      animation_frame;  // frame number
    sf::RectangleShape health_bar_background;
    sf::RectangleShape            health_bar;
};
// MOVEMENT
const float   skeleton_speed =   50.0f ;
// HEALTH
const int    skeleton_health =      40 ;
// ANIMATE
const int skeleton_frame_num =      10 ; // total skeleton frame number
// DAMAGE
const float skeleton_damage = 25 ;
// SIZE
const int enemy_width  = 32 ;
const int enemy_height = 32 ;
// POSITION
std::vector<sf::Vector2f> enemy_positions = {
        sf::Vector2f(POSX(20,enemy_width), POSY(1,enemy_height)),
        sf::Vector2f(POSX(59,enemy_width), POSY(1,enemy_height)),
        sf::Vector2f(POSX(60,enemy_width), POSY(1,enemy_height)),
        sf::Vector2f(POSX(61,enemy_width), POSY(1,enemy_height))
};

// *************** ENVIRONMENT ***************
// PLATFORM
    // SIZE
    const int  platform_width = 48 ;
    const int platform_height = 12 ;
    // POSITION
    std::vector<sf::Vector2f> jump_block_positions = {
            sf::Vector2f(JUMPBLOCKX(12), JUMPBLOCKY(2)),
            sf::Vector2f(JUMPBLOCKX(10), JUMPBLOCKY(2)),
            sf::Vector2f(JUMPBLOCKX(11), JUMPBLOCKY(2)),
            sf::Vector2f(JUMPBLOCKX(16), JUMPBLOCKY(2)),
            sf::Vector2f(JUMPBLOCKX(18), JUMPBLOCKY(3))
    };
// WALL BLOCK
    // SIZE
const float wall_block_width  = 32.0f ;
const float wall_block_height = 32.0f ;
// TREE
    // POSITION
    std::vector<float> tree_positions = {
            500 ,
            650
    };

// *************** ITEM ***************
// APPLE
    // SIZE
    const int apple_width  = 32 ;
    const int apple_height = 32 ;
    // HEALTH
    const float apple_health    = 10 ; // value that apple add to health
    //POSITION
    std::vector<sf::Vector2f> apple_positions = {
            sf::Vector2f(POSX(31,apple_width), POSY(2,apple_height)),
            sf::Vector2f(POSX(28,apple_width), POSY(2,apple_height)),
            sf::Vector2f(POSX(30,apple_width), POSY(2,apple_height)),
            sf::Vector2f(POSX(37,apple_width), POSY(2,apple_height)),
            sf::Vector2f(POSX(40,apple_width), POSY(3,apple_height))
    };

// BANANA
    // SIZE
    const int banana_width  = 32 ;
    const int banana_height = 32 ;
    // HEALTH
    const float banana_health   = 20 ; // value that banana add to health
    // POSITION
    std::vector<sf::Vector2f> banana_positions = {
            sf::Vector2f(POSX(47,banana_width), POSY(2,banana_height)),
            sf::Vector2f(POSX(45,banana_width), POSY(2,banana_height))
    };

// COIN
    // SCORE
    const int coin_score = 25 ;
    // ANIMATE
    int           coin_animation_frame =   0;
    const int coin_animation_frame_num = 12 ;
    // SIZE
    const int coin_frame_width  = 32 ;
    const int coin_frame_height = 32 ;
    // POSITION
    std::vector<sf::Vector2f> coin_positions = {
            sf::Vector2f(POSX(15,coin_frame_width) , POSY(3,coin_frame_height)),
            sf::Vector2f(POSX(16,coin_frame_width) , POSY(3,coin_frame_height)),
            sf::Vector2f(POSX(17,coin_frame_width) ,POSY(3,coin_frame_height)),
            sf::Vector2f(POSX(22,coin_frame_width) , POSY(3,coin_frame_height)),
            sf::Vector2f(POSX(23,coin_frame_width) , POSY(3,coin_frame_height))
    };

// *************** PATH ***************
// DIRECTORY PATH
const sf::String assets_directory_path     =   "../assets" ;
const sf::String background_directory_path = "/background" ;
const sf::String character_directory_path  =  "/character" ;
const sf::String object_directory_path     =     "/object" ;
const sf::String enemy_directory_path      =      "/enemy" ;
const sf::String font_directory_path       =       "/font" ;
const sf::String audio_directory_path      =      "/audio" ;
// MUSIC PATH
const sf::String main_music_path           = assets_directory_path + audio_directory_path      +       "/music.wav";
// SOUND PATH
const sf::String arrow_shoot_sound_path    = assets_directory_path + audio_directory_path      +  "/arrowShoot.ogg";
const sf::String coin_sound_path           = assets_directory_path + audio_directory_path      +        "/coin.ogg";
const sf::String apple_bite_sound_path     = assets_directory_path + audio_directory_path      +  "/apple_bite.ogg";
const sf::String jump_sound_path           = assets_directory_path + audio_directory_path      +        "/jump.ogg";
const sf::String damage_sound_path         = assets_directory_path + audio_directory_path      +      "/damage.wav";
const sf::String item_pickup_sound_path    = assets_directory_path + audio_directory_path      + "/item_pickup.wav";
// BACKGROUND PATH
const sf::String beach_background_path     = assets_directory_path + background_directory_path +      "/beach.png" ;
// TEXTURE PATH
    // CHARACTER
const sf::String right_character_path      = assets_directory_path + character_directory_path  +  "/stopRight.png" ;
const sf::String right_run_character_path  = assets_directory_path + character_directory_path  +      "/right.png" ;
const sf::String left_character_path       = assets_directory_path + character_directory_path  +   "/stopLeft.png" ;
const sf::String left_run_character_path   = assets_directory_path + character_directory_path  +       "/left.png" ;
    // ENVIRONMENT
const sf::String wall_block_path           = assets_directory_path +  object_directory_path    + "/wall_block.png" ;
const sf::String platform_path             = assets_directory_path +  object_directory_path    +   "/platform.png" ;
const sf::String tree_path                 = assets_directory_path +  object_directory_path    +       "/tree.png" ;
    // ITEM
const sf::String apple_path                = assets_directory_path +  object_directory_path    +      "/apple.png" ;
const sf::String banana_path               = assets_directory_path +  object_directory_path    +     "/banana.png" ;
const sf::String arrow_path                = assets_directory_path +  object_directory_path    +      "/arrow.png" ;
const sf::String left_arrow_path           = assets_directory_path +  object_directory_path    + "/arrow_left.png" ;
const sf::String right_arrow_path          = assets_directory_path +  object_directory_path    +"/arrow_right.png" ;
const sf::String bow_path                  = assets_directory_path +  object_directory_path    +        "/bow.png" ;
const sf::String coin_path                 = assets_directory_path +  object_directory_path    +       "/coin.png" ;
    // ENEMY
const sf::String skeleton_path             = assets_directory_path + enemy_directory_path      +   "/skeleton.png" ;
// FONT
const sf::String font_path                 = assets_directory_path +  font_directory_path      +      "/arial.ttf" ;

// *************** HEALTH BAR ***************
// MAIN SIZE
const float health_bar_background_x = 50 ;
const float health_bar_background_y =  5 ;
// BACKGROUND COLOR
const sf::Color health_bar_background_color(50, 50, 50);
// INIT SIZE
float health_bar_x = 50 ;
float health_bar_y =  5 ;
// INIT COLOR
sf::Color health_bar_color(green_color);
// OUTLINE COLOR AND THICKNESS
const sf::Color health_bar_outline_color = black_color ;
const int health_bar_outline_thickness = 1 ;



#endif //SFMLPROJECT_VALUECONFIG_H
