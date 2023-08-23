#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <SDL2/SDL_mixer.h>
#include <string>
#include <time.h>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void showText(int x, int y, int width, int height, string text, string fontName, int size, SDL_Color color, int alignVertical, int alignHorizontal, int angle);
void home_hover();
void check_leaderboard();
void selection_hover();
void TextBox(int x, int y, int code);
void showText2(int x, int y, int width, int height, string text, string fontName, int size, SDL_Color color, int alignVertical, int alignHorizontal, int angle, SDL_Renderer *renderer);

// test
void g();
//
SDL_Window *m_window;
SDL_Renderer *m_renderer;
SDL_Renderer *s_renderer;
SDL_Event *event1 = new SDL_Event();

// classes
class Tools
{
public:
    static void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, int fill_boolian);
    static void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian);
    static void my_line(SDL_Renderer *Renderer, int x_1, int y_1, int L, double theta, int widht, int R, int G, int B);
    static void texture(SDL_Renderer *m_rendererstring, string addressOfImage, int x, int y, int w, int h);
    static void rotate_texture(string addressimage, int x, int y, int w, int h, double angle);
    static int to_int(string x);
    static void showText(int x, int y, int width, int height, string text, string fontName, int size, SDL_Color color, int alignVertical, int alignHorizontal, int angle);
    static void quit();
    static void showText(int x, int y, int width, int height, string text, string fontName, int size, SDL_Color color, int alignVertical, int alignHorizontal, int angle, SDL_Renderer *renderer);
};
class Login
{
public:
    static void leader_board();
    static string search_user(string user);
    static void register_user(string username, string password);
    static void update_score();
    static void hover();
    static bool AuthLogin();
    static bool AuthRegister();
    static void show_message();
    static void TextInput();
    static void inputs();
};

class BallCompute
{
};

class InitGame
{
public:
    static void initbtn();
    static void show_magicballs();
    static void puse_button();
    static void show_scoreboard();
    static void show_timer();
    static void hover_buttons();
    static void checkpuse();
    static void move_balls();
    static void show_centerballs();
};

class Setting
{
public:
    static void btnvolume();
    static void volume(int x, int y);
    static void hover();
};

struct ball
{
    int x, y, imap, color, option = 0;
};

class BallInit
{
public:
    static void show_balls(int i);
    static void create_ball();
    static void create_ball_center();
    static void check_count_magic_ball();
    static void show_ball_center();
    static void set_mode_ballcenter();
};
class MapInit
{
public:
    static void init1();
};

struct map_xy
{
    int x, y;
};

class Arrow : public Tools
{
public:
    static void cmp_angle(int status);
    static void show_arrow();
};

class Shoting
{
public:
    static void shotingfunc();
    static bool compute_angle(int i);
    static void delete_ball(int start, int finish);
    static void setcolorsame(int i, int start, int finish);
    static bool checkraed(int i);
    static void addballgame(int i);
    static void deletesamecolor(int i);
    static void deletecolorball(int start, int finish);
    static void raed();
    static void delete_ballall();
    static void delete_allsamecolor();
    static void cmp_shotball();
    static void ball_shoted();
    static void finally();
    static void delete_ballchand(int start, int finish);
    static void raedfunc();
};

class TimeEffect
{
public:
    static void check_tepuse();
};

class Animation
{
public:
    static int start, finish;
    static void animate(int start, int finish);
    static void record(int score);
    static void raed();
    static void animateraed(int start);
    static void timeeffectanimate();
    static float easeBackIn(float p1, float p2, int time, int totalTime, float overshoot);
    static void show_leader();
    static void out_leader();
    static void choose_fields();
    static void helpme();
    static void chandanimate();
    static void ball_shoted();
    static void homeanimate();
};

class EndGame
{
public:
    static bool game_over();
    static int GivePower();
    static void confidentbox();
};

struct user
{
    string name, password;
    int lastscore = 0, record = 0, totalscore = 0, power = 0;
};

// end classes
vector<map_xy> mapgame;
vector<ball> balls;
vector<user> users;
// var
// var fo4r  counter
int color_count[] = {0, 0, 0, 0};

int rand_ball, x_arrow = 650, y_arrow = 430, jahat, mode_bg = 0, mode_time = 0, timer = 0, mode_map = 0, y_puseorfinish, x_puseorfinish = 640, shoted = 0, Z, puse = 1, rand_attr_ball, mode_play = 0, rand_ball_forattr, color, puseorfinish_time = 0, anbasht_ball = 0, rand_ball_forcolor, color_random, random_time, in_game = 0, r_btn1 = 25, r_btn2 = 25, r_btn3 = 25, r_btn4 = 25, r_btn5 = 25, x_mouse, y_mouse, on_button = 0, start_x_map, start_y_map, end_x_map, end_y_map, ball_center, tmp_ball_center = 0, mode = 0, last_ball_shoted = 0;
string path_center = "", path_tmp = "";
double angle = 0, tmpangle, angle_clear;
long long distance_ball = 10000000;
int score = 0, sofar_created = 0;
double degree_ball = 0.002;
string ball_image[] = {"red.png", "green.png", "blue.png", "bnfsh.png"};
string attr_magic_ball[] = {"pic/ice.png", "pic/mozahem.png", "pic/bird.png"};
int level = 2;
int status_magicball_screen[] = {1, 1, 1, 1, 1};
int magic_count[] = {0, 100, 0, 0, 0};
int game_overing = 0;
// this is player mabe i set this with class
string player = "";
// btn pupup
int x_soundbtn = 100;
int y_soundbtn = 50;
int x_homebtn = 100;
int y_homebtn = 50;
int mute = 1;
int x_larrow = 100, x_rarrow = 100, y_larrow = 60, y_rarrow = 60;
int x_playagainbtn = 100;
int y_playagainbtn = 50;

int x_prize = 650, y_prize = 400, w_prize = 20, h_prize = 20, t_prize = 0;
//

// shooting
int first_imap, last_imap, i_shahab;

int jahat_shot, x_shot, y_shot, R_shoted = 0;
double cosshot, sinshot;
int Rwasshoted;
//

// move ball
int step = 2;
//

// time effect
int te_puse = 1;
int et_puse_timer = 500;
int et_puse_timerbef;
int stfte = 0;
int steps[] = {0, -2, 2, 1};
int steprandom;
int teanimate = 0;
int ok = 0;
int close = 0;
int scoreboard = 0;

//

// animate
int animateframe = 0;
vector<ball> enfjar;
vector<ball> birds;
int ian = 0;
//

// animation
int timemap;
int stfa = 0, s, f;
//

// setting
int tmpx = 800;
int show_soundsetting = 0;

//

// real timer
int realtimer = 50000;
//
int raedstart;
vector<int> raedi;

//// I N I T
int play = 0;
int home = 0;
int choose_map = 0;
int login = 0;
int setting = 0;
int help = 0;
int out_leaders = 0;
double cosball, sinball;
/////

// hover login
struct sdlformat_color
{
    int R = 255, G = 255, B = 255;
} pl, ul, pr, ur;
//
struct scale
{
    int x = 150, y = 75;
} home_playbtn, home_settingbtn, home_helpbtn, home_leaderboardbtn, home_exitbtn;
// login
string usernamere = "", usernamelo = "", passwordre = "", passwordlo = "";
int message_login;
int have_message = 0;
int messagetime = 0;
int s_ur = 0, s_ul = 0, s_pr = 0, s_pl = 0;
//

// general
int iall = 0;

//
// home
int show_animate_leader = 0;
int time_leader = 0;
int timer_leadertext = 0;
int y_motion_head = 90;
int y_leader;
int x_play = 100;
int y_help = 0;
int y_scroll = 0;

//
int a = 255;

// music
Mix_Chunk *shot_sound;
Mix_Music *bgsound;
Mix_Chunk *hoverbtn;
Mix_Chunk *move_up;
Mix_Chunk *gmover;
Mix_Chunk *gift;
Mix_Chunk *key;

int musictime = 0;
int imusic = 0;
string musics[] = {"music/music0.mp3", "music/music1.mp3", "music/music2.mp3"};
int musicstime[] = {136000, 123000, 90000};
int tmpvolume;
int shufflemusic = -1;
//
double defineang;
/// load images

SDL_Texture *image0;
SDL_Texture *image1;
SDL_Texture *image2;
SDL_Texture *image3;
SDL_Texture *image4;
SDL_Texture *imagemoz;
SDL_Texture *imageice;
SDL_Texture *imagebird;
SDL_Texture *imagefire;
SDL_Texture *imagefired;
SDL_Texture *imagechand;
SDL_Texture *imagechandd;
SDL_Texture *imagetoofan;
SDL_Texture *imagetoofand;
SDL_Texture *imagebomb;
SDL_Texture *imagebombd;
SDL_Texture *imageraedd;
SDL_Texture *imageraed;
SDL_Texture *imageatash;
SDL_Texture *imagehelp;
SDL_Texture *imagebomblogo;
///

// bird mode
int sofar_deletebird = 0;
//
// test
int iraed;
int cl;
int fchand = 0;
int i_enf;
//
// end game
int power;
//

bool found = false, foundraed = false;
int index;

int i_chand;
string name = "";
SDL_Event *event = new SDL_Event();
int returntion;
//
int confident = 0;
double scno, scyes;
//

double ikey = 0;
int main(int argc, char *argv[])
{
    srand(time(0));

    int W = 800;
    int L = 1280;
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;
    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(L, W, WND_flags, &m_window, &m_renderer);
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int R = 255, G = 255, B = 255;
    SDL_RenderPresent(m_renderer);
    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    ////
    shot_sound = Mix_LoadWAV("music/Kick.wav");
    hoverbtn = Mix_LoadWAV("music/hover.wav");
    move_up = Mix_LoadWAV("music/moveup.wav");
    gmover = Mix_LoadWAV("music/hover.wav");
    gift = Mix_LoadWAV("music/chimes.wav");
    key = Mix_LoadWAV("music/key.wav");
    /////
    /// for timeeff
    srand(time(0));
    steprandom = steps[(rand() * 103 + 11) % 4];
    ///

    MapInit::init1();

    // for startGame
    int atime = 0;
    //

    // bg music
    bgsound = Mix_LoadMUS(musics[0].c_str());
    Mix_PlayMusic(bgsound, -1);
    Mix_VolumeChunk(hoverbtn, 25);
    Mix_VolumeChunk(gift, 100);
    Mix_VolumeMusic(100);

    //

    /// load images
    image0 = IMG_LoadTexture(m_renderer, "pic/0.png");
    image1 = IMG_LoadTexture(m_renderer, "pic/1.png");
    image2 = IMG_LoadTexture(m_renderer, "pic/2.png");
    image3 = IMG_LoadTexture(m_renderer, "pic/3.png");
    image4 = IMG_LoadTexture(m_renderer, "pic/4.png");

    imagemoz = IMG_LoadTexture(m_renderer, "pic/mozahem.png");
    imageice = IMG_LoadTexture(m_renderer, "pic/ice.png");
    imagebird = IMG_LoadTexture(m_renderer, "pic/bird.png");
    imagefire = IMG_LoadTexture(m_renderer, "pic/firelogo.png");
    imagefired = IMG_LoadTexture(m_renderer, "pic/firelogod.png");
    imagechand = IMG_LoadTexture(m_renderer, "pic/chand.png");
    imagechandd = IMG_LoadTexture(m_renderer, "pic/chandd.png");
    imagetoofan = IMG_LoadTexture(m_renderer, "pic/toofan.png");
    imagetoofand = IMG_LoadTexture(m_renderer, "pic/toofand.png");
    imagebombd = IMG_LoadTexture(m_renderer, "pic/bombd.png");
    imagebomb = IMG_LoadTexture(m_renderer, "pic/bomb.png");

    imageraed = IMG_LoadTexture(m_renderer, "pic/raedlogo.png");
    imageraedd = IMG_LoadTexture(m_renderer, "pic/raedlogod.png");
    imageatash = IMG_LoadTexture(m_renderer, "pic/atash.png");
    imagehelp = IMG_LoadTexture(m_renderer, "pic/helpme.png");
    imagebomblogo = IMG_LoadTexture(m_renderer, "pic/atomicbomb.png");

    while (atime < 80)
    {
        window_color(m_renderer, 0, 0, 0);
        SDL_Color color{255, 255, 255, a};
        a -= 2;
        Tools::showText(640, 200, 100, 50, "Space Blast", "GothamMedium.ttf", 45, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(770, 400, 100, 50, "Alireza Jahani      Amirreza Farzaneh", "GothamMedium.ttf", 25, color, NULL, NULL, 0);
        Tools::showText(685, 500, 100, 50, "Sharif University of Technology", "GothamMedium.ttf", 20, color, NULL, NULL, 0);
        atime++;
        SDL_Delay(25);
        SDL_RenderPresent(m_renderer);
    }
    SDL_RenderClear(m_renderer);
    login = 1;
    // home = 1;

    while (1)
    {

        //// music
        int tmptime4music = SDL_GetTicks();
        ///
        iall++;

        if (login == 1)
        {

            // window_color(m_renderer,255,200,0);
            Tools::texture(m_renderer, "pic/bgmenu.jpg", 640, 400, 1280, 800);

            Tools::texture(m_renderer, "pic/login.png", 600, 200, 200, 200);
            Tools::showText(600, 300, 100, 50, "Login & Register", "GothamMedium.ttf", 25, SDL_Color{192, 200, 150 + sin(iall / 20) * 60, 255}, NULL, NULL, 0);

            /////////////////////////////////////
            Tools::showText(200, 350, 100, 50, "Login", "GothamMedium.ttf", 25, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
            Tools::showText(100, 400, 100, 50, "Username: ", "GothamMedium.ttf", 16, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
            Tools::rect(m_renderer, 200, 413, 150, 20, ul.R, ul.G, ul.B, 1);

            Tools::showText(100, 450, 100, 50, "Password: ", "GothamMedium.ttf", 16, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
            Tools::rect(m_renderer, 200, 463, 150, 20, pl.R, pl.G, pl.B, 1);
            Tools::texture(m_renderer, "pic/loginbtn.png", 230, 530, 40, 40);
            /////////////////////////////////////////
            Tools::showText(900, 350, 100, 50, "Register", "GothamMedium.ttf", 25, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);

            Tools::showText(760, 400, 100, 50, "Username: ", "GothamMedium.ttf", 16, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
            Tools::rect(m_renderer, 860, 413, 150, 20, ur.R, ur.G, ur.B, 1);

            Tools::showText(760, 450, 100, 50, "Password: ", "GothamMedium.ttf", 16, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
            Tools::rect(m_renderer, 860, 463, 150, 20, pr.R, pr.G, pr.B, 1);
            Tools::texture(m_renderer, "pic/loginbtn.png", 883, 530, 40, 40);
            //////////////////////////////////////////

            Login::show_message();

            if (s_ul)
                TextBox(100, 200, 0);
            else if (s_pl)
                TextBox(100, 300, 1);
            else if (s_ur)
                TextBox(100, 400, 2);
            else if (s_pr)
                TextBox(100, 500, 3);

            Tools::showText(200, 400, 100, 50, usernamelo, "GothamMedium.ttf", 15, SDL_Color{0, 0, 0, 255}, NULL, NULL, 0);
            Tools::showText(200, 450, 100, 50, passwordlo, "GothamMedium.ttf", 15, SDL_Color{0, 0, 0, 255}, NULL, NULL, 0);
            Tools::showText(900, 450, 100, 50, passwordre, "GothamMedium.ttf", 15, SDL_Color{0, 0, 0, 255}, NULL, NULL, 0);
            Tools::showText(900, 400, 100, 50, usernamere, "GothamMedium.ttf", 15, SDL_Color{0, 0, 0, 255}, NULL, NULL, 0);

            //   cout << s_ul << "  " << s_pl << "  " << s_ur << "  " << s_pr << endl;
        }
        else if (home == 1)
        {
            // window_color(m_renderer,255,200,0);
            Tools::texture(m_renderer, "pic/bgmenu.jpg", 640, 400, 1280, 800);

            // play
            Tools::texture(m_renderer, "pic/buttons/playbtn.png", 640, 220, home_playbtn.x, home_playbtn.y);
            // setting
            Tools::texture(m_renderer, "pic/buttons/settingbtn.png", 640, 320, home_settingbtn.x, home_settingbtn.y);
            // help
            Tools::texture(m_renderer, "pic/buttons/helpbtn.png", 640, 420, home_helpbtn.x, home_helpbtn.y);
            // leader
            Tools::texture(m_renderer, "pic/buttons/leaderboardbtn.png", 640, 520, home_leaderboardbtn.x, home_leaderboardbtn.y);
            // exit
            Tools::texture(m_renderer, "pic/buttons/exitbtn.png", 640, 620, home_exitbtn.x, home_exitbtn.y);
        }
        else if (show_animate_leader)
        {
            Tools::texture(m_renderer, "pic/bgmenu.jpg", 640, 400, 1280, 800);

            // window_color(m_renderer,220,220,200);
            Animation::show_leader();
        }
        else if (out_leaders)
        {
            Tools::texture(m_renderer, "pic/bgmenu.jpg", 640, 400, 1280, 800);

            //  window_color(m_renderer,220,220,200);
            Animation::out_leader();
        }
        else if (help == 1)
        {
            Animation::helpme();
        }
        else if (choose_map == 1)
        {
            // window_color(m_renderer,65,46,100);
            Tools::texture(m_renderer, "pic/bgmenu.jpg", 640, 400, 1280, 800);
            Animation::choose_fields();
        }
        else if (play == 1)
        {

            int firsttime = SDL_GetTicks();

            Tools::texture(m_renderer, "pic/bg" + to_string(mode_bg + 1) + ".jpg", 640, 400, 1280, 800);

            ///
            for (int i = 0; i < mapgame.size(); i += 50)
                Tools::ellipse(m_renderer, mapgame[i].x, mapgame[i].y, 3, 3, 255, 255, 255, 1);
            ///

            TimeEffect::check_tepuse();

            if (stfa == 0 || in_game < 3)
            {
                InitGame::move_balls();
            }
            else if (stfa == 1)
            {

                Animation::animate(s, f);
                InitGame::move_balls();
            }
            else if (stfa == 2)
            {
                Animation::animateraed(raedstart);
                InitGame::move_balls();
            }
            else if (stfa == 3)
            {
                Shoting::delete_ballall();
                InitGame::move_balls();
            }
            else if (stfa == 4)
            {
                Animation::chandanimate();
                InitGame::move_balls();
            }

            Arrow::show_arrow();
            Shoting::shotingfunc();

            Animation::ball_shoted();
            InitGame::show_centerballs();
            InitGame::initbtn();

            /// test
            if (iraed > 0)
                g();

            // hole last
            // hole inter
            double cxc = (double)iall / 20.0;
            Tools::rotate_texture("pic/holei.png", mapgame[0].x, mapgame[0].y, 20 * sin(cxc) + 150, 20 * sin(cxc) + 150, iall * 4);

            if (puseorfinish_time == 0)
                Tools::rotate_texture("pic/hole.png", end_x_map, end_y_map, 100, 100, iall * 5);
            ///

            if (ok == 1 && puse == 1 && EndGame::game_over() == false)
                Animation::timeeffectanimate();

            if (puse == -1 && show_soundsetting)
                Setting::btnvolume();
            if ((stfa == 0 || in_game < 3) && puse == 1 && EndGame::game_over() == false)
                timer++;

            if (birds.size() > 0 && puse == 1 && !EndGame::game_over())
            {
                for (int i = 0; i < birds.size(); i++)
                {
                    if (birds[i].x < 1200 || birds[i].y > 0)
                    {
                        Tools::texture(m_renderer, "pic/birdf.png", birds[i].x, birds[i].y, 50, 50);
                        birds[i].x += 10;
                        birds[i].y -= 10;
                    }
                    else
                    {
                        birds.erase(birds.begin() + i, birds.begin() + i + 1);
                    }
                }
            }

            int timeloop = SDL_GetTicks() - firsttime;
            if (EndGame::game_over() == false && puse == 1)
                realtimer -= timeloop * 2;

            ian++;
        }

        if (setting == 1)
        {
            Setting::btnvolume();
        }

        if (confident == 1)
        {
            EndGame::confidentbox();
        }

        if (SDL_PollEvent(event))
        {

            if (event->type == SDL_KEYDOWN)
            {
                switch (event->key.keysym.sym)
                {
                    if (play)
                    {
                    case SDLK_RSHIFT:
                        swap(tmp_ball_center, ball_center);
                    case SDLK_LSHIFT:
                        swap(tmp_ball_center, ball_center);
                    }
                }
            }
            else if (event->type == SDL_MOUSEMOTION)
            {
                SDL_GetMouseState(&x_mouse, &y_mouse);
                Login::hover();
                if (home && !setting && !confident)
                {
                    home_hover();
                }
                if (setting)
                {
                    Setting::hover();
                }
                if (choose_map)
                {
                    selection_hover();
                }
                if (play)
                {

                    InitGame::hover_buttons();
                    Arrow::cmp_angle(0);
                }

                if (confident)
                {
                    if (x_mouse < 580 + 25 && x_mouse > 580 - 25 && y_mouse > 450 - 15 && y_mouse < 450 + 15)
                    {
                        scyes = 1.2;
                    }
                    else
                    {
                        scyes = 1;
                    }
                    if (x_mouse < 710 + 25 && x_mouse > 710 - 25 && y_mouse > 450 - 15 && y_mouse < 450 + 15)
                    {
                        scno = 1.2;
                    }
                    else
                    {
                        scno = 1;
                    }
                }
            }
            else if (event->type == SDL_MOUSEBUTTONDOWN)
            {
                if (event->button.button == SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&x_mouse, &y_mouse);

                    if (login)
                        Login::inputs();
                    //
                    BallInit::set_mode_ballcenter();

                    check_leaderboard();
                    Login::TextInput();

                    /// setting
                    if (setting)
                    {
                        Setting::volume(x_mouse, y_mouse);
                    }
                    ///

                    ///

                    // help
                    if (help)
                    {
                        if (x_mouse > 1180 - 75 && x_mouse < 1180 + 75 && y_mouse < 700 + 37 && y_mouse > 700 - 37)
                        {

                            Mix_PlayChannel(-1, shot_sound, 0);
                            home = 1;
                            help = 0;
                            ikey = 0;
                        }
                    }
                    //
                    /// selction page

                    if (choose_map)
                    {
                        if (x_mouse < 210 && x_mouse > 190 && y_mouse < 385 + 10 && y_mouse > 385 - 10)
                        {
                            mode_play = 0;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }

                        if (x_mouse < 210 && x_mouse > 190 && y_mouse < 435 + 10 && y_mouse > 435 - 10)
                        {
                            mode_play = 1;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }
                        if (x_mouse < 210 && x_mouse > 190 && y_mouse < 485 + 10 && y_mouse > 485 - 10)
                        {
                            mode_play = 2;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }

                        if (x_mouse < 735 + 10 && x_mouse > 735 - 10 && y_mouse < 380 + 10 && y_mouse > 380 - 10)
                        {
                            if (mode_bg > 0)
                                mode_bg--;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }

                        if (x_mouse < 735 + 10 && x_mouse > 735 - 10 && y_mouse < 540 + 10 && y_mouse > 540 - 10)
                        {
                            if (mode_bg < 1)
                                mode_bg++;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }

                        /// mode time
                        if (x_mouse < 210 && x_mouse > 190 && y_mouse < 505 + 10 && y_mouse > 505 - 10)
                        {
                            mode_time = 0;
                            realtimer = 50000;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }

                        if (x_mouse < 210 && x_mouse > 190 && y_mouse < 555 + 10 && y_mouse > 555 - 10)
                        {
                            mode_time = 1;
                            realtimer = 100000;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }

                        if (x_mouse < 210 && x_mouse > 190 && y_mouse < 605 + 10 && y_mouse > 605 - 10)
                        {
                            mode_time = 2;
                            realtimer = 150000;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }

                        ///

                        if (x_mouse > 1180 - 75 && x_mouse < 1180 + 75 && y_mouse < 700 + 37 && y_mouse > 700 - 37)
                        {
                            choose_map = 0;
                            Mix_PlayChannel(-1, shot_sound, 0);
                            home = 1;
                        }

                        if (x_mouse < 250 && x_mouse > 150 && y_mouse < 680 && y_mouse > 620)
                        {
                            choose_map = 0;
                            Mix_PlayChannel(-1, shot_sound, 0);
                            play = 1;
                        }
                    }

                    ///
                    /// login
                    if (login)
                    {
                        if (x_mouse < 230 + 25 && x_mouse > 230 - 25 && y_mouse > 530 - 25 && y_mouse < 530 + 25)
                        {
                            if (Login::AuthLogin())
                            {
                                login = 0;
                                home = 1;
                                Mix_PlayChannel(-1, shot_sound, 0);
                            }
                        }

                        if (x_mouse < 883 + 25 && x_mouse > 883 - 25 && y_mouse > 530 - 25 && y_mouse < 530 + 25)
                        {
                            if (Login::AuthRegister())
                            {
                                login = 0;
                                home = 1;
                                Mix_PlayChannel(-1, shot_sound, 0);
                            }
                        }
                    }
                    ///

                    /// show_animate_leader
                    if (show_animate_leader)
                    {
                        if (x_mouse < 1180 + 75 && x_mouse > 1180 - 75 && y_mouse > 700 - 37 && y_mouse < 700 + 37)
                        {
                            out_leaders = 1;
                            Mix_PlayChannel(-1, shot_sound, 0);
                            show_animate_leader = 0;
                        }
                    }
                    //////

                    /// home
                    if (home && setting == 0 && confident == 0)
                    {

                        /// home - > seeting

                        if (x_mouse < 640 + 75 && x_mouse > 640 - 75 && y_mouse < 320 + 37 && y_mouse > 320 - 37)
                        {
                            setting = 1;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }
                        ///

                        /// home - > help

                        if (x_mouse < 640 + 75 && x_mouse > 640 - 75 && y_mouse < 420 + 37 && y_mouse > 420 - 37)
                        {
                            home = 0;
                            help = 1;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }
                        ///
                        /// home - > play

                        if (x_mouse < 640 + 75 && x_mouse > 640 - 75 && y_mouse < 220 + 37 && y_mouse > 220 - 37)
                        {
                            home = 0;
                            choose_map = 1;
                            Mix_PlayChannel(-1, shot_sound, 0);
                        }
                        ///
                        /// home - > exit

                        if (x_mouse < 640 + 75 && x_mouse > 640 - 75 && y_mouse < 620 + 37 && y_mouse > 620 - 37)
                        {

                            confident = 1;
                        }
                        ///
                    }
                    ///

                    if (play)
                    {
                        InitGame::checkpuse();
                        Arrow::cmp_angle(1);
                        step = 2;
                        if (on_button == 0 && puse == 1 && EndGame::game_over() == false)
                        {
                            Mix_PlayChannel(-1, shot_sound, 0);
                            Shoting::raedfunc();
                            if (puse == 1)
                                BallInit::create_ball_center();
                            R_shoted = 0;
                            x_shot = x_mouse;
                            y_shot = y_mouse;
                            jahat_shot = -1;
                            if (x_shot > 640)
                                jahat_shot = 1;
                            Shoting::cmp_shotball();
                        }

                        // sound
                        if (puse == -1)
                        {
                            Setting::volume(x_mouse, y_mouse);
                        }

                        if (puse == -1 && x_mouse < 610 && x_mouse > 510 && y_mouse < 545 && y_mouse > 495)
                        {
                            show_soundsetting = 1;
                        }

                        if (puse == -1 && x_mouse < 720 + 50 && x_mouse > 720 - 50 && y_mouse < 545 && y_mouse > 495)
                        {
                            puse = 1;
                            sofar_created = 0;
                            puseorfinish_time = 0;
                            realtimer = 1000 * (mode_time * 50 + 50);
                            score = 0;
                            in_game = 0;

                            t_prize = 0;
                            w_prize = 0;
                            h_prize = 0;
                            balls.clear();
                            scoreboard = 0;
                            play = 0;
                            et_puse_timer = 500;
                            home = 1;
                            ian = 0;
                            timer = 0;
                            stfte = 0;
                            puseorfinish_time = 0;
                            sofar_deletebird = 0;
                            color_count[0] = 0;
                            color_count[1] = 0;
                            color_count[2] = 0;
                            color_count[3] = 0;
                        }

                        //

                        // scorenoard
                        if (EndGame::game_over() && x_mouse < 610 && x_mouse > 510 && y_mouse < 545 && y_mouse > 495)
                        {
                            realtimer = 1000 * (mode_time * 50 + 50);
                            score = 0;
                            in_game = 0;
                            sofar_created = 0;
                            t_prize = 0;
                            w_prize = 0;
                            h_prize = 0;
                            ian = 0;
                            timer = 0;
                            balls.clear();
                            et_puse_timer = 500;
                            scoreboard = 0;
                            stfte = 0;
                            birds.clear();
                            stfa = 0;
                            puseorfinish_time = 0;
                            color_count[0] = 0;
                            color_count[1] = 0;
                            color_count[2] = 0;
                            color_count[3] = 0;
                            sofar_deletebird = 0;
                            game_overing = 0;
                        }

                        if (EndGame::game_over() && x_mouse < 720 + 50 && x_mouse > 720 - 50 && y_mouse < 545 && y_mouse > 495)
                        {
                            puse = 1;
                            puseorfinish_time = 0;
                            realtimer = 100000;
                            score = 0;
                            in_game = 0;
                            t_prize = 0;
                            w_prize = 0;
                            h_prize = 0;
                            balls.clear();
                            scoreboard = 0;
                            birds.clear();
                            play = 0;
                            et_puse_timer = 500;
                            home = 1;
                            ian = 0;
                            timer = 0;
                            stfa = 0;
                            stfte = 0;
                            game_overing = 0;
                        }

                        //
                    }

                    if (confident)
                    {
                        if (x_mouse < 580 + 25 && x_mouse > 580 - 25 && y_mouse > 450 - 15 && y_mouse < 450 + 15)
                        {
                            return 0;
                        }
                        if (x_mouse < 710 + 25 && x_mouse > 710 - 25 && y_mouse > 450 - 15 && y_mouse < 450 + 15)
                        {
                            confident = 0;
                        }
                    }
                }
                if (event->button.button == SDL_BUTTON_RIGHT)
                {
                    SDL_GetMouseState(&x_mouse, &y_mouse);
                }
            }
            else if (event->type == SDL_MOUSEWHEEL)
            {

                if (show_animate_leader || out_leaders)
                {
                    y_scroll += event->wheel.y * 45;
                }
            }
            else if (event->type == SDL_QUIT)
                Tools::quit();
        }
        SDL_Delay(25);
        SDL_RenderPresent(m_renderer);
        SDL_RenderClear(m_renderer);

        //// music
        musictime += SDL_GetTicks() - tmptime4music;
        if (musictime >= musicstime[imusic])
        {
            if (shufflemusic == -1)
            {
                imusic++;
                imusic %= 3; // size
            }
            else
            {
                int next;
                while (true)
                {
                    next = rand() % 3;
                    if (next != imusic)
                    {
                        imusic = next;
                        break;
                    }
                }
            }

            bgsound = Mix_LoadMUS(musics[imusic].c_str());
            musictime = 0;
            Mix_PlayMusic(bgsound, -1);
        }
        ////
    }
}

void Tools::my_line(SDL_Renderer *Renderer, int x_1, int y_1, int L, double theta, int widht, int R, int G, int B)

{
    int x_2 = x_1 + L * cos(theta);
    int y_2 = y_1 - L * sin(theta);
    thickLineRGBA(Renderer, x_1, y_1, x_2, y_2, widht, R, G, B, 255);
}

void Tools::rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, int fill_boolian)

{
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolian == 1)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
    // SDL_RenderPresent(Renderer);
}

void Tools::ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian)
{
    if (fill_boolian == 1)
        filledEllipseRGBA(Renderer, x, y, Radius1, Radius2, R, G, B, 255);
    if (fill_boolian == 0)
        ellipseRGBA(Renderer, x, y, Radius1, Radius2, R, G, B, 255);
    // SDL_RenderPresent(Renderer);
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    SDL_RenderClear(Renderer);
    // Show the window
    // SDL_RenderPresent( Renderer );
}

// x y markaz ast
void Tools::texture(SDL_Renderer *m_rendererstring, string addressOfImage, int x, int y, int w, int h)
{
    SDL_Texture *image;
    image = IMG_LoadTexture(m_renderer, addressOfImage.c_str());

    SDL_Rect g_rect;
    g_rect.x = x - w / 2;
    g_rect.y = y - h / 2;
    g_rect.h = h;
    g_rect.w = w;
    SDL_RenderCopy(m_renderer, image, NULL, &g_rect);
    SDL_DestroyTexture(image);
}

void Tools::showText(int x, int y, int width, int height, string text, string fontName, int size, SDL_Color color, int alignVertical, int alignHorizontal, int angle)
{
    TTF_Init();
    TTF_Font *font = TTF_OpenFont((fontName).c_str(), size);
    int textWidth, textHeight;
    TTF_SizeText(font, text.c_str(), &textWidth, &textHeight);
    switch (alignHorizontal)
    {
    case 0:
        x += width - textWidth;
        break;

    case 1:
        x += (width - textWidth) / 2;
        break;
    }
    switch (alignVertical)
    {
    case 0:
        y += (height - textHeight) / 2;
        break;

    case 1:
        y += (height - textHeight);
        break;
    }

    SDL_Rect rectText{x, y, width, height};
    SDL_Surface *textSur = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *textTex = SDL_CreateTextureFromSurface(m_renderer, textSur);
    SDL_FreeSurface(textSur);
    SDL_QueryTexture(textTex, NULL, NULL, &rectText.w, &rectText.h);
    SDL_RenderCopyEx(m_renderer, textTex, NULL, &rectText, angle, NULL, SDL_FLIP_NONE);
    SDL_DestroyTexture(textTex);
    TTF_CloseFont(font);
}

void showText2(int x, int y, int width, int height, string text, string fontName, int size, SDL_Color color, int alignVertical, int alignHorizontal, int angle, SDL_Renderer *renderer)
{
    TTF_Init();
    TTF_Font *font = TTF_OpenFont((fontName).c_str(), size);
    int textWidth, textHeight;
    TTF_SizeText(font, text.c_str(), &textWidth, &textHeight);
    switch (alignHorizontal)
    {
    case 0:
        x += width - textWidth;
        break;

    case 1:
        x += (width - textWidth) / 2;
        break;
    }
    switch (alignVertical)
    {
    case 0:
        y += (height - textHeight) / 2;
        break;

    case 1:
        y += (height - textHeight);
        break;
    }

    SDL_Rect rectText{x, y, width, height};
    SDL_Surface *textSur = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *textTex = SDL_CreateTextureFromSurface(renderer, textSur);
    SDL_FreeSurface(textSur);
    SDL_QueryTexture(textTex, NULL, NULL, &rectText.w, &rectText.h);
    SDL_RenderCopyEx(renderer, textTex, NULL, &rectText, angle, NULL, SDL_FLIP_NONE);
    SDL_DestroyTexture(textTex);
    TTF_CloseFont(font);
}

// user or other things
string Login::search_user(string user)
{
    string pass = "", ts, ls, r, giftplayer;
    fstream file("users.txt", ios::in); // out deletd test
    string tmpname, passtmp;
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> tmpname >> passtmp >> ts >> ls >> r >> giftplayer;

            if (tmpname == user)
            {
                int giftnum = Tools::to_int(giftplayer);
                magic_count[giftnum - 4]++;
                return passtmp;
                break;
            }
        }
        file.close();
    }

    return pass;
}

void Login::register_user(string username, string password)
{
    fstream fout("users.txt", ios::app);
    fout << username << " " << password << " "
         << "0"
         << " "
         << "0"
         << " "
         << "0"
         << " "
         << "0" << endl;
    fout.close();
}

void InitGame::show_magicballs()
{

    SDL_Rect g_rect;
    g_rect.x = 50 - 25;
    g_rect.y = 180 - 25;
    g_rect.h = 50;
    g_rect.w = 50;

    // bomb
    if (magic_count[0] == 0)
        SDL_RenderCopy(m_renderer, imagebombd, NULL, &g_rect);
    else
    {
        SDL_RenderCopy(m_renderer, imagebomb, NULL, &g_rect);
        Tools::showText(55, 180, 50, 50, to_string(magic_count[0]) + " /", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(55, 180, 50, 50, "\\", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    }
    //    raed
    g_rect.y = 280 - 25;
    if (magic_count[1] == 0)
        SDL_RenderCopy(m_renderer, imageraedd, NULL, &g_rect);
    else
    {
        SDL_RenderCopy(m_renderer, imageraed, NULL, &g_rect);
        Tools::showText(55, 280, 50, 50, to_string(magic_count[1]) + " /", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(55, 280, 50, 50, "\\", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    }
    //    chand rang
    g_rect.y = 380 - 25;
    if (magic_count[2] == 0)
        SDL_RenderCopy(m_renderer, imagechandd, NULL, &g_rect);
    else
    {
        SDL_RenderCopy(m_renderer, imagechand, NULL, &g_rect);
        Tools::showText(55, 380, 50, 50, to_string(magic_count[2]) + "/", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(55, 380, 50, 50, "\\", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    }
    //    fire
    g_rect.y = 480 - 25;
    if (magic_count[3] == 0)
        SDL_RenderCopy(m_renderer, imagefired, NULL, &g_rect);
    else
    {
        SDL_RenderCopy(m_renderer, imagefire, NULL, &g_rect);
        Tools::showText(55, 480, 50, 50, to_string(magic_count[3]) + "/", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(55, 480, 50, 50, "\\", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    }
    //    shaab sang
    g_rect.y = 580 - 25;
    if (magic_count[4] == 0)
        SDL_RenderCopy(m_renderer, imagetoofand, NULL, &g_rect);
    else
    {
        SDL_RenderCopy(m_renderer, imagetoofan, NULL, &g_rect);
        Tools::showText(55, 580, 50, 50, to_string(magic_count[4]) + "/", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(55, 580, 50, 50, "\\", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    }
}

void InitGame::puse_button()
{
    int y_puseorfinish, x_puseorfinish = 640;
    if (!EndGame::game_over() && show_soundsetting == 0)
    {
        if (puse == 1)
            Tools::texture(m_renderer, "pic/puse0.png", 1190, 70, 100, 50);
        else
            Tools::texture(m_renderer, "pic/puse1.png", 1190, 70, 100, 50);

        // Tools::rect(m_renderer,1150,25,100,70,0,0,255,1);
    }
    if (puse == -1)
    {
        if (puseorfinish_time < 20)
        {
            y_puseorfinish = -1 * 0.35 * puseorfinish_time * puseorfinish_time + 25 * puseorfinish_time;
            puseorfinish_time++;
            Tools::texture(m_renderer, "pic/puse.png", x_puseorfinish, y_puseorfinish, 504, 325);
            Tools::texture(m_renderer, "pic/buttons/settingbtn.png", x_puseorfinish - 80, y_puseorfinish + 120, 100, 50);
            Tools::texture(m_renderer, "pic/buttons/homebtn.png", x_puseorfinish + 80, y_puseorfinish + 120, 100, 50);
        }
        else
        {
            Tools::texture(m_renderer, "pic/puse.png", 640, 400, 504, 325);
            Tools::texture(m_renderer, "pic/buttons/settingbtn.png", 640 - 80, 520, x_soundbtn, y_soundbtn);
            Tools::texture(m_renderer, "pic/buttons/homebtn.png", 640 + 80, 520, x_homebtn, y_homebtn);
        }
    }
    else if (!EndGame::game_over())
    {
        if (puseorfinish_time > 0)
        {
            y_puseorfinish = 1 * 0.32 * puseorfinish_time * puseorfinish_time + 25 * puseorfinish_time;
            puseorfinish_time--;

            Tools::texture(m_renderer, "pic/puse.png", x_puseorfinish, y_puseorfinish, 504, 325);
            Tools::texture(m_renderer, "pic/buttons/settingbtn.png", x_puseorfinish - 80, y_puseorfinish + 120, 100, 50);
            Tools::texture(m_renderer, "pic/buttons/homebtn.png", x_puseorfinish + 80, y_puseorfinish + 120, 100, 50);
        }
    }
}

void Arrow::show_arrow()
{
    double e = iall / 30.0;
    Tools::ellipse(m_renderer, 650, 430, 105, 105, 148, 153, (iall) % 256 + 100, 1);
    Tools::rotate_texture("pic/arrow.png", x_arrow, y_arrow, 200, 200, angle);
    x_arrow = 650;
    y_arrow = 430;
}

void InitGame::show_scoreboard()
{

    if (!EndGame::game_over())
    {
        Tools::texture(m_renderer, "pic/showscore.png", 1000, 70, 200, 40);
        // Tools::rect(m_renderer,800,35,250,40,0,0,255,1);
        SDL_Color color{255, 255, 255, 255};

        Tools::showText(920, 47, 100, 50, to_string(score), "GothamMedium.ttf", 20, color, NULL, NULL, 0);

        if (mode_play == 2)
        {
            Tools::texture(m_renderer, "pic/birddeleted.png", 100, 70, 111, 40);
            Tools::showText(30, 47, 100, 50, to_string(sofar_deletebird) + "/ 10", "GothamMedium.ttf", 16, color, NULL, NULL, 0);
        }
    }
    if (EndGame::game_over())
    {
        if (scoreboard == 0)
        {
            Login::update_score();
            magic_count[power - 4]++;
        }
        scoreboard = 1;
        if (puseorfinish_time < 20)
        {
            y_puseorfinish = -1 * 0.35 * puseorfinish_time * puseorfinish_time + 25 * puseorfinish_time;
            puseorfinish_time++;
            Tools::texture(m_renderer, "pic/scoreboarad.png", x_puseorfinish, y_puseorfinish, 504, 325);
            Tools::showText(600, y_puseorfinish - 50, 100, 50, "Score:  " + to_string(score), "GothamMedium.ttf", 25, SDL_Color{0, 255, 0, 255}, NULL, NULL, 0);
            Tools::texture(m_renderer, "pic/buttons/playagainbtn.png", x_puseorfinish - 80, y_puseorfinish + 120, 100, 50);
            Tools::texture(m_renderer, "pic/homebtn.png", x_puseorfinish + 80, y_puseorfinish + 120, 100, 50);
            // Mix_PlayChannel(-1,gmover,0);

            if (mode_play == 1)
                Tools::showText(700, y_puseorfinish - 50, 100, 50, "+  " + to_string((mode_time * 50 + 50 - (realtimer / 1000))), "GothamMedium.ttf", 25, SDL_Color{0, 255, 255, 255}, NULL, NULL, 0);

            Tools::showText(600, y_puseorfinish - 104, 100, 50, player, "GothamMedium.ttf", 35, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        }
        else
        {
            Tools::texture(m_renderer, "pic/scoreboarad.png", 640, 400, 504, 325);
            Tools::texture(m_renderer, "pic/buttons/playagainbtn.png", 640 - 80, 520, x_playagainbtn, y_playagainbtn);
            Tools::texture(m_renderer, "pic/homebtn.png", 640 + 80, 520, x_homebtn, y_homebtn);
            Tools::showText(600, 350, 100, 50, "Score:   " + to_string(score), "GothamMedium.ttf", 25, SDL_Color{0, 255, 0, 255}, NULL, NULL, 0);
            if (mode_` == 1)
                Tools::showText(700, 350, 100, 50, "+  " + to_string((mode_time * 50 + 50 - (realtimer / 1000))), "GothamMedium.ttf", 25, SDL_Color{0, 255, 255, 255}, NULL, NULL, 0);

            Tools::showText(600, 280, 100, 50, player, "GothamMedium.ttf", 35, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
            /// gift
            if (w_prize < 80)
            {
                w_prize += 2;
                h_prize += 2;
            }
            if (t_prize < 15)
            {
                t_prize++;
            }
            if (t_prize == 1)
                Mix_PlayChannel(-1, gift, 0);
            ///
            SDL_Rect g_rect;
            g_rect.x = x_prize - w_prize / 2;
            g_rect.y = 1.5 * t_prize * t_prize - 30 * t_prize + 350 - h_prize / 2;
            g_rect.h = w_prize;
            g_rect.w = h_prize;

            if (power == 4)
                SDL_RenderCopy(m_renderer, imagebomb, NULL, &g_rect);
            else if (power == 5)
                SDL_RenderCopy(m_renderer, imageraed, NULL, &g_rect);
            else if (power == 6)
                SDL_RenderCopy(m_renderer, imagechand, NULL, &g_rect);
            else if (power == 7)
                SDL_RenderCopy(m_renderer, imagefire, NULL, &g_rect);
            else if (power == 8)
                SDL_RenderCopy(m_renderer, imagetoofan, NULL, &g_rect);

            // Tools::texture(m_renderer,"pic/price.png",x_prize,1.5*t_prize*t_prize - 30 * t_prize + 350,w_prize,h_prize);
        }
    }
}

bool check(user &a, user &b)
{

    return a.totalscore > b.totalscore;
}

void Login::leader_board()
{
    users.clear();
    string name, totalscore, password, record, lastscore, get_power;
    string debug = "";
    fstream file("users.txt", ios::in);
    if (file.is_open())
    {
        while (!file.eof())
        {

            // username password lastscore totalscore record_in_one_game get_power
            file >> name >> password >> lastscore >> totalscore >> record >> get_power;

            if (debug != name)
            {
                user u;
                u.name = name;
                u.password = password;
                u.lastscore = Tools::to_int(lastscore);
                u.record = Tools::to_int(record);
                u.totalscore = Tools::to_int(totalscore);
                u.power = Tools::to_int(get_power);
                users.push_back(u);
            }

            debug = name;
        }
        file.close();
    }

    sort(users.begin(), users.end(), check);
}

void Login::update_score()
{
    Login::leader_board();

    string name, totalscore, password, record, lastscore;
    fstream file("users.txt", ios::out | ios::trunc);

    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].name << "   " << player << " " << score << endl;
        if (users[i].name == player)
        {

            int time_score = 0;
            if (mode_play == 1)
                time_score = (mode_time * 50 + 50 - (realtimer / 1000));
            users[i].lastscore = score + time_score;
            users[i].totalscore += score + time_score;
            if (users[i].record < score + time_score)
            {
                Animation::record(score);
                users[i].record = score + time_score;
            }

            users[i].power = EndGame::GivePower();
            power = users[i].power;
            magic_count[users[i].power]++;
            cout << users[i].lastscore << endl;
        }
        cout << users[i].name << "   " << player << " " << score << endl;
        cout << "-----------" << endl;
        file << users[i].name << " " << users[i].password << " " << users[i].lastscore << " " << users[i].totalscore << " " << users[i].record << " " << users[i].power << endl;
    }
    //  score = 0;
}
void BallInit::create_ball()
{
    srand(time(0));
    int rand_time = rand() * 23 + 3;
    color = rand() % 4;
    ball balltmp;
    balltmp.color = color;
    balltmp.option = 0;

    // imap
    balltmp.imap = 0;
    balltmp.x = 0;
    balltmp.y = 0;

    int choose = 3;
    //  mode_play = 1;//test
    if (mode_play == 2) // bird
        choose = 4;

    rand_attr_ball = (rand() * 7 + 19) % (choose - 1) + 1; // 3;
    rand_ball_forattr = (rand() * 4 + 1) % 3;              // 6
    rand_ball_forcolor = rand_time % 4;
    color_random = (rand() * 11 + 9) % 3;

    int rand_ball_chand = (rand_time * 2 + 41) % 8;

    for (int i = 0; i < level; i++)
    {
        // if ok i want set a property for one of this same color

        if (i == rand_ball_forcolor)
            balltmp.color = color_random;

        if (i == rand_ball_forattr)
        {
            balltmp.option = rand_attr_ball;
        }
        else if (i == rand_ball_chand && balltmp.option == 0)
            balltmp.color = 4;

        balls.insert(balls.begin(), balltmp);

        balltmp.color = color;
        balltmp.option = 0;
    }
}

// ممکنه باگ بخوره
void BallInit::create_ball_center()
{
    srand(time(0));

    if (mode == 0)
    {
        last_ball_shoted = ball_center;
        ball_center = tmp_ball_center;
        if (color_count[0] != 0 || color_count[1] != 0 || color_count[2] != 0 || color_count[3] != 0)
        {
            while (true)
            {
                random_time = rand() % 4;
                if (color_count[random_time] != 0)
                {
                    tmp_ball_center = random_time;
                    break;
                }
            }
        }
        else
        {
            tmp_ball_center = 0;
        }
    }
    else
    {
        tmp_ball_center = ball_center;
        ball_center = mode;

        mode = 0;
    }
}

void BallInit::check_count_magic_ball()
{

    if (magic_count[0] == 0)
        status_magicball_screen[0] = 1;
    else
        status_magicball_screen[0] = 0;

    if (magic_count[1] == 0)
        status_magicball_screen[1] = 1;
    else
        status_magicball_screen[1] = 0;

    if (magic_count[2] == 0)
        status_magicball_screen[2] = 1;
    else
        status_magicball_screen[2] = 0;

    if (magic_count[3] == 0)
        status_magicball_screen[3] = 1;
    else
        status_magicball_screen[3] = 0;

    if (magic_count[4] == 0)
        status_magicball_screen[4] = 1;
    else
        status_magicball_screen[4] = 0;
}

bool EndGame::game_over()
{
    // mode_play 0->80ball  1->timer 2->parande

    if (game_overing)
    {
        return true;
    }

    if (mode_play == 0 && sofar_created >= 80 && in_game <= 2)
        return true;

    if (mode_play == 1 && realtimer / 1000 <= 0)
        return true;
    if (mode_play == 2 && sofar_deletebird >= 5)
        return true;

    return false;
}

void BallInit::show_ball_center()
{

    switch (ball_center)
    {
    case 0:
        path_center = "blue.png";
        break;

    case 1:
        path_center = "yellow.png";
        break;

    case 2:
        path_center = "red.png";
        break;

    case 3:
        path_center = "green.png";
        break;

    case 4:
        path_center = "bomb.png";
        break;

    case 5:
        path_center = "raed.png";
        break;

    case 6:
        path_center = "soal.png";
        break;

    case 7:
        path_center = "fire.png";
        break;

    case 8:
        path_center = "all_clear.png";
        break;
    }

    switch (tmp_ball_center)
    {
    case 0:
        path_tmp = "blue.png";
        break;

    case 1:
        path_tmp = "yellow.png";
        break;

    case 2:
        path_tmp = "red.png";
        break;

    case 3:
        path_tmp = "green.png";
        break;

    case 4:
        path_tmp = "bomb.png";
        break;

    case 5:
        path_tmp = "raed.png";
        break;

    case 6:
        path_tmp = "soal.png";
        break;

    case 7:
        path_tmp = "fire.png";
        break;

    case 8:
        path_tmp = "all_clear.png";
        break;
    }

    //  show  //
}

void BallInit::show_balls(int i)
{
    SDL_Rect g_rect;
    g_rect.x = balls[i].x - 25;
    g_rect.y = balls[i].y - 25;
    g_rect.h = 50;
    g_rect.w = 50;

    if (balls[i].color == 4)
    {
        Tools::texture(m_renderer, "pic/chand.png", balls[i].x, balls[i].y, 50, 50);
    }
    else if (balls[i].option == 1)
    {
        // x y
        //  Tools::texture(m_renderer,attr_magic_ball[0],balls[i].x,balls[i].y,80,80);

        if (balls[i].color == 0)
            SDL_RenderCopy(m_renderer, image0, NULL, &g_rect);
        else if (balls[i].color == 1)
            SDL_RenderCopy(m_renderer, image1, NULL, &g_rect);
        else if (balls[i].color == 2)
            SDL_RenderCopy(m_renderer, image2, NULL, &g_rect);
        else
            SDL_RenderCopy(m_renderer, image3, NULL, &g_rect);

        SDL_RenderCopy(m_renderer, imageice, NULL, &g_rect);
    }
    else if (balls[i].option)
    {

        if (balls[i].option == 2)
            SDL_RenderCopy(m_renderer, imagemoz, NULL, &g_rect);
        else
            SDL_RenderCopy(m_renderer, imagebird, NULL, &g_rect);
    }
    else
    {
        if (balls[i].color == 0)
            SDL_RenderCopy(m_renderer, image0, NULL, &g_rect);
        else if (balls[i].color == 1)
            SDL_RenderCopy(m_renderer, image1, NULL, &g_rect);
        else if (balls[i].color == 2)
            SDL_RenderCopy(m_renderer, image2, NULL, &g_rect);
        else
            SDL_RenderCopy(m_renderer, image3, NULL, &g_rect);
        // Tools::texture(m_renderer,ball_image[balls[i].color],balls[i].x,balls[i].y,25,25);
    }

    //  show  //
}

void BallInit::set_mode_ballcenter()
{

    //
    if (x_mouse > 25 && x_mouse < 75 && y_mouse < 215 && y_mouse > 155 && magic_count[0] != 0 && puse == 1)
    {
        mode = 4;
        magic_count[0]--;
    }

    if (x_mouse > 25 && x_mouse < 75 && y_mouse < 315 && y_mouse > 255 && magic_count[1] != 0 && puse == 1)
    {
        mode = 5;
        magic_count[1]--;
    }

    if (x_mouse > 25 && x_mouse < 75 && y_mouse < 415 && y_mouse > 355 && magic_count[2] != 0 && puse == 1)
    {
        mode = 6;
        magic_count[2]--;
    }

    if (x_mouse > 25 && x_mouse < 75 && y_mouse < 515 && y_mouse > 455 && magic_count[3] != 0 && puse == 1)
    {
        mode = 7;
        magic_count[3]--;
    }

    if (x_mouse > 25 && x_mouse < 75 && y_mouse < 615 && y_mouse > 555 && magic_count[4] != 0 && puse == 1)
    {
        mode = 8;
        magic_count[4]--;
    }
    if (puse == 1 && mode != 0)
        create_ball_center();
}

void Arrow::cmp_angle(int status)
{
    if (status == 1)
        shoted = 1;
    double a = (double)(430 - y_mouse) / (double)(x_mouse - 650);
    Z = 0;
    tmpangle = atan(a) * 180 / M_PI * -1;
    if ((x_mouse - 650) < 0)
        Z = 180;
    angle_clear = tmpangle;
    jahat = -1;
    if (x_mouse > 650)
        jahat = 1;

    angle = tmpangle + Z;

    if (status == 1)
    {
        x_arrow -= (x_mouse - 650) * 0.1;
        y_arrow += (430 - y_mouse) * 0.1;
    }
}

void InitGame::hover_buttons()
{
    // hover
    on_button = 0;
    if (EndGame::game_over() == false && puse == 1 && x_mouse > 25 && x_mouse < 75 && y_mouse < 215 && y_mouse > 155)
    {
        on_button = 1;
        r_btn1 = 30;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        r_btn1 = 25;
    }
    if (EndGame::game_over() == false && puse == 1 && x_mouse > 25 && x_mouse < 75 && y_mouse < 315 && y_mouse > 255)
    {
        on_button = 1;
        r_btn2 = 30;
        //  Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        r_btn2 = 25;
    }

    if (EndGame::game_over() == false && puse == 1 && x_mouse > 25 && x_mouse < 75 && y_mouse < 415 && y_mouse > 355)
    {
        on_button = 1;
        r_btn3 = 30;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        r_btn3 = 25;
    }

    if (EndGame::game_over() == false && puse == 1 && x_mouse > 25 && x_mouse < 75 && y_mouse < 515 && y_mouse > 455)
    {
        on_button = 1;
        r_btn4 = 30;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        r_btn4 = 25;
    }

    if (EndGame::game_over() == false && puse == 1 && x_mouse > 25 && x_mouse < 75 && y_mouse < 615 && y_mouse > 555)
    {
        on_button = 1;
        r_btn5 = 30;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        r_btn5 = 25;
    }

    if (x_mouse > 1070 && x_mouse < 1170 && y_mouse < 100 && y_mouse > 30)
    {
        on_button = 1;
    }

    if (puse == -1 && x_mouse < 610 && x_mouse > 510 && y_mouse<545 & y_mouse> 495)
    {
        x_soundbtn = 120;
        y_soundbtn = 60;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        x_soundbtn = 100;
        y_soundbtn = 50;
    }

    if (x_mouse < 760 && x_mouse > 670 && y_mouse<545 & y_mouse> 495)
    {
        x_homebtn = 120;
        y_homebtn = 60;
        //   Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        x_homebtn = 100;
        y_homebtn = 50;
    }

    //

    if (EndGame::game_over() && x_mouse < 610 && x_mouse > 510 && y_mouse<545 & y_mouse> 495)
    {
        x_playagainbtn = 120;
        y_playagainbtn = 60;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        x_playagainbtn = 100;
        y_playagainbtn = 50;
    }

    //

    if (show_soundsetting && x_mouse < 640 && x_mouse > 540 && y_mouse < 380 && y_mouse > 320)
    {
        x_larrow = 120;
        y_larrow = 60;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        x_larrow = 100;
        y_larrow = 50;
    }

    if (show_soundsetting && x_mouse < 730 && x_mouse > 630 && y_mouse < 380 && y_mouse > 320)
    {
        x_rarrow = 120;
        y_rarrow = 60;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        x_rarrow = 100;
        y_rarrow = 50;
    }
    // end hover
}

int Tools::to_int(string x)
{
    int l = 0, i = 0;
    int n = x.length();
    while (i < n)
    {
        l *= 10;
        l += x[i] - 48;
        i++;
    }
    return l;
}

void Tools::quit()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
}

void Tools::rotate_texture(string addressimage, int x, int y, int w, int h, double angle)
{
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    SDL_Texture *myTexture;
    int n = addressimage.length();
    char char_array[n + 1];

    strcpy(char_array, addressimage.c_str());
    myTexture = IMG_LoadTexture(m_renderer, char_array);
    SDL_Rect texr1;
    texr1.x = x - w / 2;
    texr1.y = y - h / 2;
    texr1.w = w;
    texr1.h = h;
    SDL_RenderCopyEx(m_renderer, myTexture, NULL, &texr1, angle, NULL, flipType);
    SDL_DestroyTexture(myTexture);
}

void InitGame::initbtn()
{
    puse_button();
    show_magicballs();
    show_scoreboard();
    // hover_buttons();
    if (mode_play == 1)
        InitGame::show_timer();
}

void InitGame::checkpuse()
{
    if (x_mouse > 1150 && x_mouse < 1250 && y_mouse > 25 && y_mouse < 95 && EndGame::game_over() == false)
        puse *= -1;
}

void MapInit::init1()
{
    end_x_map = 580;
    end_y_map = 580;
    double RX = 400, RY = 400;
    timemap = 30;
    for (int i = 0; i < 6000; i++)
    {
        map_xy m;
        m.x = 650 - RX * cos(i * degree_ball - 0.5);
        m.y = 430 - RY * sin(i * degree_ball - 0.5);
        mapgame.push_back(m);
        RX -= 0.04;
        RY -= 0.04;
    }
}

void InitGame::move_balls()
{

    int tme = timemap;
    if (timer % tme == 0 && EndGame::game_over() == false && stfa == 0)
    {
        if (mode_play == 0 && sofar_created <= 80 && step != -2)
        {

            if (timer % 2 == 0)
            {
                in_game++;
                BallInit::create_ball();
                sofar_created++;
            }
        }
        if (mode_play == 1)
        {
            in_game++;
            BallInit::create_ball();
        }
        else if (mode_play == 2)
        {
            in_game++;
            BallInit::create_ball();
        }
    }

    ///
    color_count[0] = 0;
    color_count[1] = 0;
    color_count[2] = 0;
    color_count[3] = 0;

    ///
    for (int i = balls.size() - in_game + 2; i < balls.size(); i++)
    {
        int colors[][3] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 0, 255}};

        if (balls[i].imap >= 0)
        {
            BallInit::show_balls(i);
            if (balls[i].imap > 100 && balls[i].option < 2)
            {
                color_count[balls[i].color]++;
            }

            balls[i].x = mapgame[balls[i].imap].x;
            balls[i].y = mapgame[balls[i].imap].y;
        }

        if (puse == 1 && EndGame::game_over() == false && stfa == 0)
        {
            if (step != -2)
            {
                if (in_game < 3)
                {
                    balls[balls.size() - 1].imap++;
                    continue;
                }
                if (i != balls.size() - 1 && (balls[i].x - balls[i + 1].x) * (balls[i].x - balls[i + 1].x) + (balls[i].y - balls[i + 1].y) * (balls[i].y - balls[i + 1].y) >= 2500)
                    balls[i].imap += step;
                else if (i == balls.size() - 1)
                    balls[i].imap += step;
            }
            else
            {
                balls[i].imap += step;
                if (balls[i].imap < 0)
                    in_game--;
            }
        }

        if (balls[balls.size() - 1].imap > mapgame.size())
            game_overing = 1;
    }
}

void Shoting::shotingfunc()
{

    for (int i = balls.size() - in_game + 1; i < balls.size(); i++)
    {

        if (ball_center != 5)
        {
            if (Shoting::compute_angle(i))
            {

                found = true;
                index = i;
                return;
            }
        }
    }
}

void Shoting::raedfunc()
{

    if (ball_center == 5)
    {
        int uu = 0;
        for (int i = balls.size() - in_game + 2; i < balls.size(); i++)
        {
            if (Shoting::checkraed(i))
            {

                foundraed = true;
                uu = 1;
                raedi.push_back(i);
            }
        }
        if (uu == 1)
            Shoting::raed();
    }
}
void Shoting::delete_ballall()
{

    color_count[0] = 0;
    color_count[1] = 0;
    color_count[2] = 0;
    color_count[3] = 0;
    if (i_shahab > 0)
    {
        string image = "pic/shahab/";
        image += to_string(iall % 10);
        image += ".png";
        Tools::texture(m_renderer, image.c_str(), mapgame[i_shahab].x, mapgame[i_shahab].y, 100, 100);
        i_shahab -= 40;
    }

    if (abs(i_shahab - balls[last_imap].imap) < 30)
    {
        Mix_PlayChannel(-1, move_up, 0);
        balls.erase(balls.begin() + last_imap, balls.begin() + last_imap + 1);
        in_game--;
        Tools::showText(mapgame[balls[last_imap].imap].x + 5, mapgame[balls[last_imap].imap].y, 50, 50, "+5", "GothamMedium.ttf", 25, SDL_Color{255, 0, 0, 255}, NULL, NULL, 0);
        Shoting::deletecolorball(last_imap, last_imap + 1);
        last_imap--;
        score += 5;
    }
    // pass

    if (abs(i_shahab - balls[last_imap].imap) == 0)
        stfa = 0;
}

bool Shoting::compute_angle(int i)
{

    int nx = 650 + R_shoted * cosshot;
    int ny = 430 - R_shoted * sinshot;
    if ((balls[i].x - nx) * (balls[i].x - nx) + (balls[i].y - ny) * (balls[i].y - ny) < 50 * 50)
    {
        return true;
    }

    return false;
}

void Shoting::delete_ball(int start, int finish)
{
    if (finish + 1 < balls.size() && start - 1 >= balls.size() - in_game + 1 && balls[finish + 1].color == balls[start - 1].color && balls[finish + 1].option == 0 && balls[start - 1].option == 0)
        returntion = 1;
    else
        returntion = 0;

    enfjar.clear();
    int low = start, high = finish + 1;
    if (start < balls.size() - in_game + 1)
        low = balls.size() - in_game + 1;
    if (high > balls.size())
        high = balls.size();

    for (int i = low; i < high; i++)
    {
        ball b;
        b.color = balls[i].color;
        b.imap = balls[i].imap;
        enfjar.push_back(b);
    }

    
    balls.erase(balls.begin() + low, balls.begin() + high);
    in_game -= high - low;
    stfa = 1;
    animateframe = 0;
    Animation::animate(low, high);
    s = low, f = high;
    score += (high - low) * 5;

    // for birds
    // birds.clear();
    if (start - 1 >= balls.size() - in_game + 1 && balls[start - 1].option == 3)
    {
        ball bird;
        bird.x = balls[start - 1].x;
        bird.y = balls[start - 1].y;
        bird.imap = balls[start - 1].imap;
        birds.push_back(bird);
        Shoting::delete_ball(start - 1, start - 1);
        sofar_deletebird++;
    }
    if (start < balls.size() && balls[start].option == 3)
    {
        ball bird;
        bird.x = balls[start].x;
        bird.y = balls[start].y;
        bird.imap = balls[start].imap;
        birds.push_back(bird);
        Shoting::delete_ball(start, start);
        sofar_deletebird++;
    }
    ////
}

void Shoting::delete_ballchand(int start, int finish)
{

    enfjar.clear();
    int low = start, high = finish + 1;
    if (start < balls.size() - in_game + 1)
        low = balls.size() - in_game + 1;
    if (high > balls.size())
        high = balls.size();

    for (int i = low; i < high; i++)
    {
        ball b;
        b.color = balls[i].color;
        b.imap = balls[i].imap;
        enfjar.push_back(b);
    }

    balls.erase(balls.begin() + low, balls.begin() + high);
    in_game -= high - low;
    stfa = 1;
    animateframe = 0;
    Animation::animate(low, high);
    s = low, f = high;
    score += (high - low) * 5;
    ////
}

void Animation::animate(int start, int finish)
{
    Mix_PlayChannel(-1, move_up, 0);

    // for  foranimate to clear
    int v = 0;

    // return ball;
    int distnc = (balls[start].x - balls[start - 1].x) * (balls[start].x - balls[start - 1].x) + (balls[start].y - balls[start - 1].y) * (balls[start].y - balls[start - 1].y);

    // for mode 0 after create all 80 ball and rotate
    if (mode_play == 0 && sofar_created > 80 && start == balls.size() - in_game + 1)
    {
        stfa = 0;
        return;
    }
    if (distnc == 474445)
    {
        stfa = 0;
        return;
    }

    for (int i = start; i < balls.size(); i++)
    {
        int distnc = (balls[i].x - balls[i - 1].x) * (balls[i].x - balls[i - 1].x) + (balls[i].y - balls[i - 1].y) * (balls[i].y - balls[i - 1].y);
        if (distnc > 3000)
        {
            v = 1;
            /// in
            balls[i].imap -= 20;
            balls[i].imap = max(0, balls[i].imap);
            balls[i].x = mapgame[balls[i].imap].x;
            balls[i].y = mapgame[balls[i].imap].y;
        }
    }

    if (animateframe < 3)
    {
        for (int i = 0; i < enfjar.size(); i++)
        {
            v = 1;
            string addenf = "pic/enf";
            addenf += to_string(enfjar[i].color);
            addenf += to_string(animateframe);
            addenf += ".png";
            Tools::texture(m_renderer, addenf.c_str(), mapgame[enfjar[i].imap].x, mapgame[enfjar[i].imap].y, 50, 50);
            Tools::showText(mapgame[enfjar[i].imap].x, mapgame[enfjar[i].imap].y - 20, 50, 50, "+5", "GothamMedium.ttf", 15, SDL_Color{255, 0, 0, 255}, NULL, NULL, 0);
        }

        if (ian % 2 == 0)
            animateframe++;
    }

    if (v == 0)
    {
        if (returntion)
            Shoting::deletesamecolor(start);
        else
            stfa = 0;
    }
}

void Shoting::setcolorsame(int i, int start, int finish)
{
    int colorset = balls[i].color;
    for (int i = start; i < finish + 1 && i < balls.size(); i++)
    {
        if (balls[i].color < 4 && balls[i].option == 0)
        {
            color_count[colorset]++;
            color_count[balls[i].color]--;
            balls[i].color = colorset;
        }
    }
}

bool Shoting::checkraed(int i)
{
    double a_ball = (double)(balls[i].y * -1 + 430) / (double)(balls[i].x * -1 + 650);
    double angleball = atan(a_ball) * 180 / M_PI;
    int x_ball = balls[i].x * -1 + 650;
    int y_ball = balls[i].y * -1 + 430;
    angleball = atan(a_ball) * 180 / M_PI;
    if (balls[i].imap != 0 && abs(angle_clear - angleball) <= 120 * 180 / (sqrt(x_ball * x_ball + y_ball * y_ball)) / M_PI && jahat * x_ball < 0)
    {

        return true;
    }
    return false;
}

void Shoting::addballgame(int i)
{
    ball b;
    if (i != balls.size() - 1)
    {
        b.x = mapgame[balls[i].imap].x;
        b.y = mapgame[balls[i].imap].y;
        b.imap = balls[i].imap;
    }
    else
    {
        b.x = mapgame[balls[i].imap].x;
        b.y = mapgame[balls[i].imap].y;
        b.imap = balls[i].imap;
    }
    b.color = last_ball_shoted;
    balls.insert(balls.begin() + i, b);
    for (int j = i + 1; j < balls.size(); j++)
    {
        balls[j].imap += 70;
        balls[j].x = mapgame[balls[j].imap].x;
        balls[j].y = mapgame[balls[j].imap].y;
    }
    in_game++;
    color_count[ball_center]++;
    // balls.insert(balls.begin() + i + 1,b);
}

void Shoting::deletesamecolor(int index)
{

    int high = -1, low = 1, h = 1, l = 1;
    while (h == 1 || l == 1)
    {
        if (h && index + high >= balls.size() - in_game + 1 && balls[high + index].color == balls[index].color)
        {

            if (balls[high + index].option == 1)
            {
                h = 0;

                balls[high + index].option = 0;
            }
            else if (balls[high + index].option == 0)
                high--;
            else
            {
                h = 0;
            }
        }
        else
            h = 0;
        if (l && index + low < balls.size() && balls[low + index].color == balls[index].color)
        {
            if (balls[index + low].option == 1)
            {
                l = 0;
                balls[low + index].option = 0;
            }
            else if (balls[low + index].option == 0)
                low++;
            else
            {
                l = 0;
            }
        }
        else
            l = 0;
    }
    high++;

    if (low - high > 2)
    {
        color_count[balls[index].color] -= low - high;
        Shoting::delete_ball(index + high, index + low - 1);
    }
    else if (!returntion)
        Shoting::addballgame(index);
    else
        returntion = 0;
}

void Animation::record(int score)
{
    // animate after record
    return;
}

void Shoting::deletecolorball(int start, int finish)
{
    for (int i = start; i < finish; i++)
    {
        if (balls[i].color < 4 && balls[i].option == 0)
            color_count[balls[i].color]--;
    }
}

void Shoting::raed()
{
    enfjar.clear();

    for (int i = raedi.size() - 1; i >= 0; i--)
    {
        ball b;
        b.option = 0;
        b.color = balls[raedi[i]].color;
        b.imap = balls[raedi[i]].imap;
        enfjar.push_back(b);
        balls.erase(balls.begin() + raedi[i], balls.begin() + raedi[i] + 1);
        score += 5;
        in_game--;
    }
    stfa = 2;
    raedstart = raedi[0];

    ///
    if (balls[raedi[0] - 1].color == balls[raedi[raedi.size() - 1] + 1].color && balls[raedi[raedi.size() - 1] + 1].option == 0 && balls[raedi[0] - 1].option == 0)
        returntion = 1;
    // else
    //   returntion =0;
    ///

    Animation::animateraed(raedi[0]);

    raedi.clear();

    iraed = 10;
}
void g()
{
    string add = "pic/raed";
    add += to_string(iraed % 7);
    add += ".png";
    int rects[][2] = {{88, 900}, {153, 2158}, {210, 1440}, {865, 2908}, {357, 2751}, {209, 2583}, {46, 689}};
    Tools::rotate_texture(add.c_str(), 640, 400, rects[iraed % 7][1] * 0.25, rects[iraed % 7][0] * 0.25, defineang);

    iraed--;
}
void Animation::animateraed(int start)
{

    Mix_PlayChannel(-1, move_up, 0);

    if (mode_play == 0 && sofar_created > 80 && start == balls.size() - in_game + 1)
    {
        stfa = 0;
        return;
    }

    bool v = 0;
    int s = 0;
    for (int i = start; i < balls.size(); i++)
    {
        int distnc = (balls[i].x - balls[i - 1].x) * (balls[i].x - balls[i - 1].x) + (balls[i].y - balls[i - 1].y) * (balls[i].y - balls[i - 1].y);
        if (distnc > 3000 && distnc != 474445)
        {
            v = 1;
            /// in
            balls[i].imap -= 20;
            balls[i].imap = max(0, balls[i].imap);
            balls[i].x = mapgame[balls[i].imap].x;
            balls[i].y = mapgame[balls[i].imap].y;
        }
    }

    if (animateframe < 3)
    {
        v = 1;
        for (int i = 0; i < enfjar.size(); i++)
        {
            string addenf = "pic/enf";
            addenf += to_string(enfjar[i].color);
            addenf += to_string(animateframe);
            addenf += ".png";
            Tools::texture(m_renderer, addenf.c_str(), mapgame[enfjar[i].imap].x, mapgame[enfjar[i].imap].y, 50, 50);
            Tools::showText(mapgame[enfjar[i].imap].x, mapgame[enfjar[i].imap].y - 20, 50, 50, "+5", "GothamMedium.ttf", 15, SDL_Color{255, 0, 0, 255}, NULL, NULL, 0);
        }

        /// in v
        if (ian % 2 == 0)
            animateframe++;
    }
    //    if(v == 0 )
    //    {
    //        stfa = 0;
    //
    //    }

    if (v == 0)
    {
        if (returntion)
            Shoting::deletesamecolor(raedstart);
        else
        {
            stfa = 0;
            animateframe = 0;
        }
    }
}
//
void TimeEffect::check_tepuse()
{
    if (timer == et_puse_timer && stfte >= 0 && puse == 1 && EndGame::game_over() == false)
    {
        et_puse_timerbef = et_puse_timer;
        et_puse_timer += 700;
        step = steprandom; //-2;

        if (step != 2)
            ok = 1;
    }
    else if (et_puse_timerbef + 150 == timer)
        step = 2;
}

int EndGame::GivePower()
{

    int powers[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    int choose_random = powers[rand() % 15];
    return choose_random + 4;
}
void Animation::timeeffectanimate()
{
    if (teanimate < 25 && close == 0)
    {
        Tools::texture(m_renderer, "pic/timeeffect.png", 650, 430, 25 * teanimate, 15 * teanimate);
        teanimate++;
        if (teanimate == 25)
            close = 1;
    }
    else if (close == 1)
    {
        Tools::texture(m_renderer, "pic/timeeffect.png", 650, 430, 25 * teanimate, 15 * teanimate);
        teanimate--;

        if (teanimate == 0)
        {
            ok = 0;
            close = 0;
        }
    }
}

void Setting::btnvolume()
{

    Tools::texture(m_renderer, "pic/bgmenu.png", 640, 400, 1280, 800);

    Tools::texture(m_renderer, "pic/volume.png", 640, 400, 504, 325);
    // close btn
    Tools::texture(m_renderer, "pic/close.png", 860, 260, 30, 30);

    Tools::rect(m_renderer, 450, 460, 800 - 450, 10, 157, 163, 234, 1);
    Tools::rect(m_renderer, 450, 460, tmpx - 450, 10, 0, 0, 255, 1);
    Tools::showText(580, 400, 100, 50, "Volume", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    Tools::ellipse(m_renderer, tmpx, 465, 10, 10, 68, 79, 215, 1);

    Tools::showText(570, 300, 100, 50, "Music", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    if (imusic < 2)
        Tools::texture(m_renderer, "pic/rightarrow.png", 680, 350, x_rarrow, y_rarrow);
    else
        Tools::texture(m_renderer, "pic/rightarrowd.png", 680, 350, x_rarrow, y_rarrow);
    if (imusic > 0)
        Tools::texture(m_renderer, "pic/leftarrow.png", 590, 350, x_larrow, y_larrow);
    else
        Tools::texture(m_renderer, "pic/leftarrowd.png", 590, 350, x_larrow, y_larrow);

    if (mute == -1)
    {
        Tools::texture(m_renderer, "pic/mute.png", 470, 300, 40, 40);
    }
    else
    {
        Tools::texture(m_renderer, "pic/unmute.png", 470, 300, 40, 40);
    }

    Tools::showText(400, 350, 100, 50, "Shuffle Music", "GothamMedium.ttf", 15, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    if (shufflemusic == 1)
    {
        Tools::texture(m_renderer, "pic/tic.png", 520, 375, 20, 20);
    }
    else
    {
        Tools::texture(m_renderer, "pic/untic.png", 520, 375, 20, 20);
    }
}
void Setting::volume(int x, int y)
{
    // close
    if (x_mouse > 860 - 15 && x_mouse < 860 + 15 && y_mouse < 260 + 15 && y_mouse > 260 - 15)
    {
        show_soundsetting = 0;
        if (setting)
        {
            home = 1;
            setting = 0;
        }
    }
    if (imusic > 0 && x < 640 && x > 540 && y < 380 && y > 320)
    {
        if (shufflemusic == -1)
            imusic--;
        else
        {
            int next;
            while (true)
            {
                next = rand() % 3;
                if (next != imusic)
                {
                    imusic = next;
                    break;
                }
            }
        }
        musictime = 0;
        bgsound = Mix_LoadMUS(musics[imusic].c_str());
        Mix_PlayMusic(bgsound, -1);
    }
    if (imusic < 2 && x < 730 && x > 630 && y < 380 && y > 320)
    {

        if (shufflemusic == -1)
            imusic++;
        else
        {
            int next;
            while (true)
            {
                next = rand() % 3;
                if (next != imusic)
                {
                    imusic = next;
                    break;
                }
            }
        }
        musictime = 0;
        bgsound = Mix_LoadMUS(musics[imusic].c_str());
        Mix_PlayMusic(bgsound, -1);
    }

    if (x > 425 && x < 475 && y < 325 && y > 275)
    {
        mute *= -1;
    }

    if (mute == -1)
    {
        tmpx = 450;
        Mix_VolumeMusic(0);
    }
    else
    {

        if (y_mouse > 450 && y_mouse < 470)
        {
            if (x > 800)
                tmpx = 800;
            else if (x <= 450)
                tmpx = 450;
            else
                tmpx = x;
        }
        Mix_VolumeMusic((tmpx - 450) * 100 / 350);
    }

    if (x_mouse > 520 - 10 && x_mouse < 520 + 10 && y_mouse < 375 + 10 && y_mouse > 375 - 10)
    {
        shufflemusic *= -1;
    }
}

void InitGame::show_timer()
{

    int fsize, x = 24;
    fsize = 16;
    SDL_Color color{255, 255, 255, 255};

    Tools::texture(m_renderer, "pic/timer.png", 100, 40, 150, 30);
    x = 60;
    if (realtimer / 1000 < 10 && realtimer / 1000 % 2 == 0)
    {
        fsize = 20;
        x = 65;
        color = {255, 0, 0, 255};
    }
    Tools::showText(x, 15, 50, 50, to_string(realtimer / 1000), "GothamMedium.ttf", fsize, color, NULL, NULL, 0);
}

void Login::hover()
{

    int x = x_mouse;
    int y = y_mouse;

    if (x < 350 && x > 200 && y < 433 && y > 413)
    {
        ul.R = 255;
        ul.B = 0;
        ul.G = 0;
    }
    else
    {
        ul.R = 255;
        ul.B = 255;
        ul.G = 255;
    }

    if (x < 350 && x > 200 && y < 483 && y > 463)
    {
        pl.R = 255;
        pl.B = 0;
        pl.G = 0;
    }
    else
    {
        pl.R = 255;
        pl.B = 255;
        pl.G = 255;
    }

    if (x < 1010 && x > 860 && y < 433 && y > 413)
    {
        ur.R = 255;
        ur.B = 0;
        ur.G = 0;
    }
    else
    {
        ur.R = 255;
        ur.B = 255;
        ur.G = 255;
    }

    if (x < 1010 && x > 860 && y < 483 && y > 463)
    {
        pr.R = 255;
        pr.B = 0;
        pr.G = 0;
    }
    else
    {
        pr.R = 255;
        pr.B = 255;
        pr.G = 255;
    }
}

void Login::inputs()
{

    int d = 0;

    int x = x_mouse;
    int y = y_mouse;

    if (x < 350 && x > 200 && y < 433 && y > 413)
    {
        s_ul = 1;
        s_ur = 0;
        s_pl = 0;
        s_pr = 0;
    }

    else if (x < 350 && x > 200 && y < 483 && y > 463)
    {
        s_ul = 0;
        s_ur = 0;
        s_pl = 1;
        s_pr = 0;
    }
    else if (x < 1010 && x > 860 && y < 433 && y > 413)
    {
        s_ul = 0;
        s_ur = 1;
        s_pl = 0;
        s_pr = 0;
    }
    else if (x < 1010 && x > 860 && y < 483 && y > 463)
    {
        s_ul = 0;
        s_ur = 0;
        s_pl = 0;
        s_pr = 1;
    }
    else
    {
        s_ul = 0;
        s_ur = 0;
        s_pl = 0;
        s_pr = 0;
    }
}

bool Login::AuthLogin()
{
    have_message = 1;
    messagetime = 0;
    a = 255;
    string pass = Login::search_user(usernamelo);
    if (usernamelo != "" && passwordlo != "" && pass != "" && pass == passwordlo)
    {
        player = usernamelo;

        return true;
    }
    else if (usernamelo == "" || passwordlo == "")
    {
        message_login = 2;
    }
    else
    {
        message_login = 1;
    }

    return false;
}
bool Login::AuthRegister()
{
    have_message = 1;
    messagetime = 0;
    a = 255;
    string pass = Login::search_user(usernamere);

    if (usernamere != "" && pass == "")
    {
        Login::register_user(usernamere, passwordre);
        player = usernamere;
        return true;
    }
    else if (pass != "")
    {
        message_login = 0;
    }
    else
    {
        message_login = 2;
    }

    return false;
}

void Login::show_message()
{

    if (messagetime < 30)
    {
        if (have_message)
        {
            if (message_login == 0)
            {
                Tools::showText(630, 350, 150, 50, "User Already have Account.", "GothamMedium.ttf", 25, SDL_Color{0, 0, 255, a}, NULL, NULL, 0);
            }

            if (message_login == 1)
            {
                Tools::showText(725, 330, 150, 50, "Username or Password is Wrong if you don't have account register first.", "GothamMedium.ttf", 16, SDL_Color{255, 0, 0, a}, NULL, NULL, 0);
            }

            if (message_login == 2)
            {
                Tools::showText(555, 350, 150, 50, "Must be full field.", "GothamMedium.ttf", 25, SDL_Color{35, 25, 10, a}, NULL, NULL, 0);
            }

            if (messagetime > 15)
                a -= 15;
        }

        messagetime++;
    }
}

void Login::TextInput()
{
    // SDL_StartTextInput();
    int x = x_mouse;
    int y = y_mouse;

    SDL_Event *e = new SDL_Event();

    if (x < 350 && x > 200 && y < 433 && y > 413)
    {
        while (true)
        {
            SDL_PollEvent(e);
            if (e->type == SDL_TEXTINPUT)
            {

                usernamelo += e->text.text;
            }
            else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_BACKSPACE && usernamelo.size())
            {
                usernamelo.pop_back();
            }
            else if (e->button.button == SDL_BUTTON_LEFT)
            {
                break;
            }
        }
    }

    else if (x < 350 && x > 200 && y < 483 && y > 463)
    {
        if (e->type == SDL_TEXTINPUT)
        {
            passwordlo += e->text.text;
        }
        else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_BACKSPACE && passwordlo.size())
        {
            passwordlo.pop_back();
        }
    }

    else if (x < 1010 && x > 860 && y < 433 && y > 413)
    {

        if (e->type == SDL_TEXTINPUT)
        {
            usernamere += e->text.text;
        }
        else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_BACKSPACE && usernamere.size())
        {
            usernamere.pop_back();
        }
    }

    if (x < 1010 && x > 860 && y < 483 && y > 463)
    {
        if (event->type == SDL_TEXTINPUT)
        {
            passwordre += event->text.text;
        }
        else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_BACKSPACE && passwordre.size())
        {
            passwordre.pop_back();
        }
    }
}

// etc

void home_hover()
{

    int x = x_mouse;
    int y = y_mouse;
    if (x < 640 + 75 && x > 640 - 75 && y < 220 + 37 && y > 220 - 37)
    {

        home_playbtn.x = 180;
        home_playbtn.y = 90;
        Mix_PlayChannel(-1, hoverbtn, 0);
    }
    else
    {
        home_playbtn.x = 150;
        home_playbtn.y = 75;
    }

    if (x < 640 + 75 && x > 640 - 75 && y < 320 + 37 && y > 320 - 37)
    {
        home_settingbtn.x = 180;
        home_settingbtn.y = 90;
        Mix_PlayChannel(-1, hoverbtn, 0);
    }
    else
    {
        home_settingbtn.x = 150;
        home_settingbtn.y = 75;
    }

    if (x < 640 + 75 && x > 640 - 75 && y < 420 + 37 && y > 420 - 37)
    {
        home_helpbtn.x = 180;
        home_helpbtn.y = 90;
        Mix_PlayChannel(-1, hoverbtn, 0);
    }
    else
    {
        home_helpbtn.x = 150;
        home_helpbtn.y = 75;
    }

    if (x < 640 + 75 && x > 640 - 75 && y < 520 + 37 && y > 520 - 37)
    {
        home_leaderboardbtn.x = 180;
        home_leaderboardbtn.y = 90;
        Mix_PlayChannel(-1, hoverbtn, 0);
    }
    else
    {
        home_leaderboardbtn.x = 150;
        home_leaderboardbtn.y = 75;
    }

    if (x < 640 + 75 && x > 640 - 75 && y < 620 + 37 && y > 620 - 37)
    {
        home_exitbtn.x = 180;
        home_exitbtn.y = 90;
        Mix_PlayChannel(-1, hoverbtn, 0);
    }
    else
    {
        home_exitbtn.x = 150;
        home_exitbtn.y = 75;
    }
}

void check_leaderboard()
{
    int x = x_mouse;
    int y = y_mouse;
    if (x < 640 + 75 && x > 640 - 75 && y < 520 + 37 && y > 520 - 37 && home && !setting && !confident)
    {
        home = 0;
        time_leader = 0;
        show_animate_leader = 1;
        timer_leadertext = 0;
        y_motion_head = 90;
    }
}

float Animation::easeBackIn(float p1, float p2, int time, int totalTime, float overshoot)
{
    float d = p2 - p1;
    double s = overshoot;
    double t = time / (double)totalTime;
    return d * t * t * ((s + 1) * t - s) + p1;
}

void Animation::show_leader()
{

    if (time_leader < 20)
    {
        y_leader = -1 * 0.35 * time_leader * time_leader + 25 * time_leader;
        time_leader++;
        Tools::texture(m_renderer, "pic/spopup.png", 640, y_leader, 800, 600);
    }
    else
    {
        Tools::texture(m_renderer, "pic/spopup.png", 640, 400, 800, 600);
        Login::leader_board();

        Tools::showText(280, y_motion_head, 100, 50, "Player", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(510, y_motion_head, 100, 50, "Totalscore", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(720, y_motion_head, 100, 50, "Lastscore", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(900, y_motion_head, 100, 50, "Record", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);

        if (y_motion_head < 130)
            y_motion_head += 10;

        int y_motion = 185 + y_scroll * -1;
        if (y_motion > 185)
            y_motion = 185;

        float ttemp = Animation::easeBackIn(100, 160, timer_leadertext, 20, 0.5);

        SDL_Color gold{212, 175, 55, 255};
        SDL_Color silver{170, 169, 173, 255};
        SDL_Color boronz{169, 113, 66, 255};
        SDL_Color color;

        for (int i = 0; i < users.size(); i++)
        {

            if (y_motion > 150 && y_motion < 640)
            {
                if (users[i].name == player)
                {
                    Tools::ellipse(m_renderer, ttemp + 100, y_motion + 25, 5, 5, 255, 0, 0, 1);
                }
                if (i == 0)
                {
                    color = gold;
                    Tools::texture(m_renderer, "pic/gold.png", ttemp + 130, y_motion + 22, 30, 40);
                }
                else if (i == 1)
                {
                    color = silver;
                    Tools::texture(m_renderer, "pic/silver.png", ttemp + 130, y_motion + 25, 30, 40);
                }
                else if (i == 2)
                {
                    color = boronz;
                    Tools::texture(m_renderer, "pic/boronz.png", ttemp + 130, y_motion + 28, 30, 40);
                }
                else
                    color = {0, 0, 0, 255};
                if (i != 0 && i != 1 && i != 2)
                    Tools::showText(ttemp + 35, y_motion, 100, 50, to_string(i + 1) + "-", "GothamMedium.ttf", 20, SDL_Color{255, 0, 0, 255}, NULL, NULL, 0);
                Tools::showText(ttemp + 150, y_motion, 100, 50, users[i].name, "GothamMedium.ttf", 25, color, NULL, NULL, 0);
                Tools::showText(ttemp + 350, y_motion, 100, 50, to_string(users[i].totalscore), "GothamMedium.ttf", 25, color, NULL, NULL, 0);
                Tools::showText(ttemp + 550, y_motion, 100, 50, to_string(users[i].lastscore), "GothamMedium.ttf", 25, color, NULL, NULL, 0);
                Tools::showText(ttemp + 750, y_motion, 100, 50, to_string(users[i].record), "GothamMedium.ttf", 25, color, NULL, NULL, 0);
            }

            y_motion += 38;
        }

        // Tools::texture(m_renderer,"pic/gard.png",640,180,790,35);
        //   Tools::texture(m_renderer,"pic/gard.png",640,670,730,30);

        if (y_scroll == -4)
            Tools::showText(600, 700, 100, 50, "END List", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);

        if (timer_leadertext < 20 && y_motion_head >= 110)
            timer_leadertext++;

        Tools::texture(m_renderer, "pic/homebtn.png", 1180, 700, 150, 75);
    }
}

void Animation::out_leader()
{
    Tools::texture(m_renderer, "pic/spopup.png", 640, y_leader + 55, 800, 600);
    Tools::showText(280, y_motion_head, 100, 50, "Player", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    Tools::showText(510, y_motion_head, 100, 50, "Totalscore", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    Tools::showText(720, y_motion_head, 100, 50, "Lastscore", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    Tools::showText(900, y_motion_head, 100, 50, "Record", "GothamMedium.ttf", 25, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    if (y_motion_head > -50)
        y_motion_head -= 10;

    int y_motion = 185 + y_scroll * -1;
    if (y_motion > 185)
        y_motion = 185;
    float ttemp = Animation::easeBackIn(140, 300, timer_leadertext, 20, 0.5);

    SDL_Color gold{212, 175, 55, 255};
    SDL_Color silver{170, 169, 173, 255};
    SDL_Color boronz{169, 113, 66, 255};
    SDL_Color color;

    for (int i = 0; i < users.size(); i++)
    {
        if (y_motion > 150 && y_motion < 640)
        {
            if (users[i].name == player)
            {
                Tools::ellipse(m_renderer, ttemp + 100, y_motion + 25, 5, 5, 255, 0, 0, 1);
            }
            if (i == 0)
            {
                color = gold;
                Tools::texture(m_renderer, "pic/gold.png", ttemp + 130, y_motion + 25, 30, 30);
            }
            else if (i == 1)
            {
                color = silver;
                Tools::texture(m_renderer, "pic/silver.png", ttemp + 130, y_motion + 25, 30, 30);
            }
            else if (i == 2)
            {
                color = boronz;
                Tools::texture(m_renderer, "pic/boronz.png", ttemp + 130, y_motion + 25, 30, 30);
            }
            else
                color = {0, 0, 0, 255};
            if (i != 0 && i != 1 && i != 2)
                Tools::showText(ttemp + 35, y_motion, 100, 50, to_string(i + 1) + "-", "GothamMedium.ttf", 20, SDL_Color{255, 0, 0, 255}, NULL, NULL, 0);
            Tools::showText(ttemp + 150, y_motion, 100, 50, users[i].name, "GothamMedium.ttf", 25, color, NULL, NULL, 0);
            Tools::showText(ttemp + 350, y_motion, 100, 50, to_string(users[i].totalscore), "GothamMedium.ttf", 25, color, NULL, NULL, 0);
            Tools::showText(ttemp + 550, y_motion, 100, 50, to_string(users[i].lastscore), "GothamMedium.ttf", 25, color, NULL, NULL, 0);
            Tools::showText(ttemp + 750, y_motion, 100, 50, to_string(users[i].record), "GothamMedium.ttf", 25, color, NULL, NULL, 0);
        }
        y_motion += 38;
    }

    // Tools::texture(m_renderer,"pic/gard.png",640,180,790,35);
    // Tools::texture(m_renderer,"pic/gard.png",640,670,730,30);

    timer_leadertext++;

    Tools::texture(m_renderer, "pic/homebtn.png", 1180, 700, 150, 75);

    if (time_leader > -15 && y_motion_head < 10)
    {
        y_leader = -1 * 0.45 * time_leader * time_leader + 25 * time_leader;
        time_leader--;
    }
    if (time_leader == -15)
    {
        out_leaders = 0;
        home = 1;
        y_scroll = 0;
    }
}

void Animation::choose_fields()
{

    Tools::texture(m_renderer, "pic/homebtn.png", 1180, 700, 150, 75);

    Tools::showText(630, 150, 150, 75, "Selection Room", "GothamMedium.ttf", 40, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);

    Tools::showText(160, 300, 150, 75, "Select your game mode:", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    Tools::showText(630, 300, 150, 75, "Select your bg:", "GothamMedium.ttf", 20, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);

    Tools::showText(15, 350, 150, 75, "Classic", "GothamMedium.ttf", 16, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    Tools::showText(20, 400, 150, 75, "Timeing", "GothamMedium.ttf", 16, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    Tools::showText(15, 450, 150, 75, "birds", "GothamMedium.ttf", 16, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);

    if (mode_play == 0)
    {
        Tools::texture(m_renderer, "pic/tic.png", 200, 385, 20, 20);
        Tools::texture(m_renderer, "pic/untic.png", 200, 435, 20, 20);
        Tools::texture(m_renderer, "pic/untic.png", 200, 485, 20, 20);
    }
    else if (mode_play == 1)
    {
        Tools::texture(m_renderer, "pic/untic.png", 200, 385, 20, 20);
        Tools::texture(m_renderer, "pic/tic.png", 200, 435, 20, 20);
        Tools::texture(m_renderer, "pic/untic.png", 200, 485, 20, 20);

        Tools::showText(30, 440, 150, 75, "Time:", "GothamMedium.ttf", 16, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);

        Tools::showText(30, 470, 150, 75, "50", "GothamMedium.ttf", 16, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(30, 520, 150, 75, "100", "GothamMedium.ttf", 16, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        Tools::showText(30, 570, 150, 75, "150", "GothamMedium.ttf", 16, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
        if (mode_time == 0)
        {
            Tools::texture(m_renderer, "pic/tic.png", 200, 505, 20, 20);
            Tools::texture(m_renderer, "pic/untic.png", 200, 555, 20, 20);
            Tools::texture(m_renderer, "pic/untic.png", 200, 605, 20, 20);
        }
        if (mode_time == 1)
        {
            Tools::texture(m_renderer, "pic/untic.png", 200, 505, 20, 20);
            Tools::texture(m_renderer, "pic/tic.png", 200, 555, 20, 20);
            Tools::texture(m_renderer, "pic/untic.png", 200, 605, 20, 20);
        }
        if (mode_time == 2)
        {
            Tools::texture(m_renderer, "pic/untic.png", 200, 505, 20, 20);
            Tools::texture(m_renderer, "pic/untic.png", 200, 555, 20, 20);
            Tools::texture(m_renderer, "pic/tic.png", 200, 605, 20, 20);
        }
    }
    else if (mode_play == 2)
    {
        Tools::texture(m_renderer, "pic/untic.png", 200, 385, 20, 20);
        Tools::texture(m_renderer, "pic/untic.png", 200, 435, 20, 20);
        Tools::texture(m_renderer, "pic/tic.png", 200, 435 + 50, 20, 20);
    }

    string bgpath = "pic/bg";
    bgpath += to_string(mode_bg + 1);
    bgpath += ".jpg";
    Tools::texture(m_renderer, bgpath.c_str(), 735, 460, 200, 120);
    Tools::texture(m_renderer, "pic/up.png", 735, 380, 20, 20);
    Tools::texture(m_renderer, "pic/down.png", 735, 540, 20, 20);

    // PLAY BTN
    Tools::texture(m_renderer, "pic/playbtn.png", 200, 650, x_play, x_play / 2 + 10);
}

void selection_hover()
{
    if (x_mouse < 250 && x_mouse > 150 && y_mouse < 680 && y_mouse > 620)
    {
        x_play = 120;
    }
    else
    {
        x_play = 100;
    }
}

void Animation::helpme()
{
    if (ikey == 0)
    {
        Mix_PlayChannel(-1, key, 0);
    }

    Tools::texture(m_renderer, "pic/bgmenu.jpg", 640, 400, 1280, 800);
    Tools::texture(m_renderer, "pic/homebtn.png", 1180, 700, 150, 75);
    Tools::texture(m_renderer, "pic/helpbg.png", 640, 400, 1000, 600);
    string Text = "When You Born you don't have a booklet to help you for talking,walking and... so you don't need help to play this easy game.any way:";
    Tools::showText(100 + ikey * 8, 200, 100, 50, Text.substr(0, ikey), "GothamMedium.ttf", 16, SDL_Color{255, 255, 255, 255}, NULL, NULL, 0);
    if (ikey < Text.length())
    {
        ikey++;
    }
    if (ikey == Text.length())
    {
        SDL_Delay(100);
        ikey++;
    }
    else
    {
        SDL_Rect g_rect;
        g_rect.x = 300;
        g_rect.y = 270;
        g_rect.h = 370;
        g_rect.w = 638;
        SDL_RenderCopy(m_renderer, imagehelp, NULL, &g_rect);
    }
}

void Setting::hover()
{

    if (imusic > 0 && x_mouse < 640 && x_mouse > 540 && y_mouse < 380 && y_mouse > 320)
    {
        x_larrow = 120;
        y_larrow = 60;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        x_larrow = 100;
        y_larrow = 50;
    }

    if (imusic < 2 && x_mouse < 730 && x_mouse > 630 && y_mouse < 380 && y_mouse > 320)
    {
        x_rarrow = 120;
        y_rarrow = 60;
        // Mix_PlayChannel(-1,hoverbtn,0);
    }
    else
    {
        x_rarrow = 100;
        y_rarrow = 50;
    }
}

void TextBox(int x, int y, int code)
{

    string input3;
    if (code == 0)
        input3 = usernamelo;
    if (code == 1)
        input3 = passwordlo;
    if (code == 2)
        input3 = usernamere;
    if (code == 3)
        input3 = passwordre;

    int font = 2;
    bool caps_lock = false;

    bool quit = false;
    char ch = 0;
    int l = 0;
    while (!quit)
    {
        l++;
        Tools::texture(m_renderer, "pic/bgmenu.jpg", 640, 400, 1280, 800);

        Tools::texture(m_renderer, "pic/login.png", 600, 200, 200, 200);
        Tools::showText(600, 300, 100, 50, "Login & Register", "GothamMedium.ttf", 25, SDL_Color{192, 200, 150 + sin(iall / 20) * 60, 255}, NULL, NULL, 0);

        /////////////////////////////////////
        Tools::showText(200, 350, 100, 50, "Login", "GothamMedium.ttf", 25, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
        Tools::showText(100, 400, 100, 50, "Username: ", "GothamMedium.ttf", 16, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
        Tools::rect(m_renderer, 200, 413, 150, 20, ul.R, ul.G, ul.B, 1);

        Tools::showText(100, 450, 100, 50, "Password: ", "GothamMedium.ttf", 16, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
        Tools::rect(m_renderer, 200, 463, 150, 20, pl.R, pl.G, pl.B, 1);
        Tools::texture(m_renderer, "pic/loginbtn.png", 230, 530, 40, 40);
        /////////////////////////////////////////
        Tools::showText(900, 350, 100, 50, "Register", "GothamMedium.ttf", 25, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);

        Tools::showText(760, 400, 100, 50, "Username: ", "GothamMedium.ttf", 16, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
        Tools::rect(m_renderer, 860, 413, 150, 20, ur.R, ur.G, ur.B, 1);

        Tools::showText(760, 450, 100, 50, "Password: ", "GothamMedium.ttf", 16, SDL_Color{123, 61, 207, 255}, NULL, NULL, 0);
        Tools::rect(m_renderer, 860, 463, 150, 20, pr.R, pr.G, pr.B, 1);
        Tools::texture(m_renderer, "pic/loginbtn.png", 883, 530, 40, 40);
        //////////////////////////////////////////

        Tools::showText(200, 400, 100, 50, usernamelo, "GothamMedium.ttf", 15, SDL_Color{249, 215, 30, 255}, NULL, NULL, 0);
        Tools::showText(200, 450, 100, 50, passwordlo, "GothamMedium.ttf", 15, SDL_Color{249, 215, 30, 255}, NULL, NULL, 0);
        Tools::showText(900, 450, 100, 50, passwordre, "GothamMedium.ttf", 15, SDL_Color{249, 215, 30, 255}, NULL, NULL, 0);
        Tools::showText(900, 400, 100, 50, usernamere, "GothamMedium.ttf", 15, SDL_Color{249, 215, 30, 255}, NULL, NULL, 0);

        SDL_Delay(15);
        SDL_RenderPresent(m_renderer);
        if (SDL_PollEvent(event1))
        {
            if (event1->type == SDL_KEYUP)
            {

                switch (event1->key.keysym.sym)
                {
                case SDLK_SPACE:
                    ch = ' ';
                    break;

                case SDLK_RETURN:
                    quit = true;
                    break;
                case SDLK_CAPSLOCK:
                    ch = 0;
                    caps_lock = !caps_lock;
                    break;
                case SDLK_BACKSPACE:
                    ch = 0;
                    if (input3.length() != 0)
                    {
                        input3 = input3.substr(0, input3.length() - 1);
                    }
                    break;
                default:
                    if (event1->key.keysym.sym != SDLK_UP && event1->key.keysym.sym != SDLK_DOWN && event1->key.keysym.sym != SDLK_LEFT && event1->key.keysym.sym != SDLK_RIGHT)
                        ch = event1->key.keysym.sym;
                    break;
                }
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == ' ') && input3.length() < 25 && !quit)
                {
                    if (caps_lock == 1 && ch != ' ' && input3.length() < 10)
                        input3 += ch + 'A' - 'a';
                    else if (input3.length() < 10)
                        input3 += ch;
                }
            }
            else if (event1->type == SDL_MOUSEBUTTONDOWN)
            {
                if (event1->button.button == SDL_BUTTON_LEFT)
                {
                    break;
                }
            }
        }

        if (code == 0)
        {
            usernamelo = input3;
            if (l % 20 < 10)
                usernamelo += "|";
        }
        if (code == 1)
        {
            passwordlo = input3;
            if (l % 20 < 10)
                passwordlo += "|";
        }
        if (code == 2)
        {
            usernamere = input3;
            if (l % 20 < 10)
                usernamere += "|";
        }
        if (code == 3)
        {
            passwordre = input3;
            if (l % 20 < 10)
                passwordre += "|";
        }
    }

    if (code == 0)
    {
        s_ul = 0;
        if (usernamelo[usernamelo.length() - 1] == '|')
        {
            usernamelo.pop_back();
        }
    }
    if (code == 1)
    {
        s_pl = 0;
        if (passwordlo[passwordlo.length() - 1] == '|')
        {
            passwordlo.pop_back();
        }
    }
    if (code == 2)
    {
        s_ur = 0;
        if (usernamere[usernamere.length() - 1] == '|')
        {
            usernamere.pop_back();
        }
    }
    if (code == 3)
    {
        s_pr = 0;
        if (passwordre[passwordre.length() - 1] == '|')
        {
            passwordre.pop_back();
        }
    }

    return;
}
void Shoting::delete_allsamecolor()
{

    enfjar.clear();
    color_count[cl] = 0;
    for (int i = balls.size() - in_game + 2; i < balls.size(); i)
    {
        if (balls[i].color == cl)
        {
            ball b;
            b.color = balls[i].color;
            b.imap = balls[i].imap;
            enfjar.push_back(b);
            balls.erase(balls.begin() + i, balls.begin() + i + 1);
            in_game--;
        }
        else
            i++;
    }

    stfa = 4;

    i_enf = 0;
}
void Animation::chandanimate()
{
    Mix_PlayChannel(-1, move_up, 0);

    for (int i = i_enf; i < enfjar.size(); i++)
    {

        string addenf = "pic/enf";
        addenf += to_string(enfjar[i].color);
        addenf += to_string(iall % 4);
        addenf += ".png";
        Tools::texture(m_renderer, addenf.c_str(), mapgame[enfjar[i].imap].x, mapgame[enfjar[i].imap].y, 50, 50);
        Tools::showText(mapgame[enfjar[i].imap].x, mapgame[enfjar[i].imap].y - 20, 50, 50, "+5", "GothamMedium.ttf", 15, SDL_Color{255, 0, 0, 255}, NULL, NULL, 0);
    }

    int v = 0;
    for (int i = balls.size() - in_game + 2; i < balls.size(); i++)
    {
        int distnc = (balls[i].x - balls[i - 1].x) * (balls[i].x - balls[i - 1].x) + (balls[i].y - balls[i - 1].y) * (balls[i].y - balls[i - 1].y);
        if (distnc > 3500 && distnc != 474445)
        {
            v = 1;
            /// in
            balls[i].imap -= 25;
            balls[i].imap = max(0, balls[i].imap);
            balls[i].x = mapgame[balls[i].imap].x;
            balls[i].y = mapgame[balls[i].imap].y;
        }
    }

    i_enf++;

    if (v == 0)
        stfa = 0;
}

// AX11
void Shoting::cmp_shotball()
{
    double n = (double)(430 - y_shot) / (double)(x_shot - 650);

    sinshot = sin(atan(n));
    cosshot = cos(atan(n));
    if (jahat_shot == -1)
    {
        cosshot *= -1;
        sinshot *= -1;
    }
    defineang = angle;
}

void Animation::ball_shoted()
{

    SDL_Rect g_rect, rex;
    g_rect.x = 650 + R_shoted * cosshot - 25;
    g_rect.y = 430 - R_shoted * sinshot - 25;
    g_rect.h = 50;
    g_rect.w = 50;

    if (last_ball_shoted == 0)
        SDL_RenderCopy(m_renderer, image0, NULL, &g_rect);
    else if (last_ball_shoted == 1)
        SDL_RenderCopy(m_renderer, image1, NULL, &g_rect);
    else if (last_ball_shoted == 2)
        SDL_RenderCopy(m_renderer, image2, NULL, &g_rect);
    else if (last_ball_shoted == 3)
        SDL_RenderCopy(m_renderer, image3, NULL, &g_rect);
    else if (last_ball_shoted == 4)
    {

        rex.x = 650 + R_shoted * cosshot - 50;
        rex.y = 430 - R_shoted * sinshot - 15;
        rex.h = 30;
        rex.w = 100;
        SDL_RenderCopyEx(m_renderer, imagebomblogo, NULL, &rex, defineang, NULL, SDL_FLIP_NONE);
    }
    else if (last_ball_shoted == 6)
        SDL_RenderCopy(m_renderer, imagechand, NULL, &g_rect);
    else if (last_ball_shoted == 8)
        SDL_RenderCopy(m_renderer, imagetoofan, NULL, &g_rect);
    else if (last_ball_shoted == 7)
    {
        g_rect.x = 650 + R_shoted * cosshot - 150;
        g_rect.y = 430 - R_shoted * sinshot - 25;
        g_rect.h = 50;
        g_rect.w = 300;
        SDL_RenderCopyEx(m_renderer, imageatash, NULL, &g_rect, defineang, NULL, SDL_FLIP_NONE);
    }

    if (last_ball_shoted != 255)
    {
        if (found == false)
        {
            R_shoted += 50;
        }
        else
        {
            R_shoted = 0;
            Shoting::finally();
            found = false;
            last_ball_shoted = 255;
        }
    }
}

void Shoting::finally()
{

    if (found)
    {

        switch (last_ball_shoted)
        {

        // bomb
        case 4:
            Shoting::delete_ball(index - 2, index + 2);
            Shoting::deletecolorball(index - 2, index + 3);
            break;

        // ?
        case 6:
            fchand = 1;
            cl = balls[index].color;
            stfa = 4;
            i_chand = 0;
            Shoting::delete_allsamecolor();
            // Shoting::setcolorsame(index,index-2,index+2);
            break;

        // fireball
        case 7:
            if (balls[index].option == 1)
                balls[index].option = 0;
            else if (balls[index].option == 0)
            {
                Shoting::deletecolorball(index, index + 1);
                Shoting::delete_ball(index, index);
            }
            else
            {
                Shoting::delete_ball(index, index);
            }
            break;

        // کنفیکون
        case 8:
            first_imap = balls.size() - in_game + 1;
            last_imap = balls.size() - 1;
            i_shahab = mapgame.size();
            Shoting::delete_ballall();
            stfa = 3;
            Shoting::deletecolorball(0, balls.size());
            break;

        default:
            if (balls[index].color == 4)
            {
                int high = index + 3;
                int low = index - 3;
                if (high >= balls.size())
                    high = balls.size();
                if (low < 0)
                    low = 0;
                // color count bayad bzari
                for (int i = low; i < high; i++)
                {
                    balls[i].color = last_ball_shoted;
                }
            }
            else if (balls[index].color == last_ball_shoted && balls[index].option == 0)
            {
                Shoting::deletesamecolor(index);
            }
            else if (balls[index].option == 2)
            {
                Shoting::delete_ball(index, index);
            }
            else if (last_ball_shoted != 5)
            {
                Shoting::addballgame(index);
            }
            break;
        }
    }
}

void InitGame::show_centerballs()
{

    double n = (double)(430 - y_mouse) / (double)(x_mouse - 650);

    sinball = sin(atan(n));
    cosball = cos(atan(n));
    if (jahat == -1)
    {
        cosball *= -1;
        sinball *= -1;
    }

    SDL_Rect g_rect;
    g_rect.x = 650 - 35;
    g_rect.y = 430 - 35;
    g_rect.h = 70;
    g_rect.w = 70;
    int colors[][3] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}, {255, 0, 255}};
    if (ball_center == 0)
        SDL_RenderCopy(m_renderer, image0, NULL, &g_rect);
    else if (ball_center == 1)
        SDL_RenderCopy(m_renderer, image1, NULL, &g_rect);
    else if (ball_center == 2)
        SDL_RenderCopy(m_renderer, image2, NULL, &g_rect);
    else if (ball_center == 3)
        SDL_RenderCopy(m_renderer, image3, NULL, &g_rect);

    else if (ball_center == 4)
        SDL_RenderCopy(m_renderer, imagebomb, NULL, &g_rect);
    else if (ball_center == 5)
        SDL_RenderCopy(m_renderer, imageraed, NULL, &g_rect);
    else if (ball_center == 6)
        SDL_RenderCopy(m_renderer, imagechand, NULL, &g_rect);
    else if (ball_center == 7)
        SDL_RenderCopy(m_renderer, imagefire, NULL, &g_rect);
    else if (ball_center == 8)
        SDL_RenderCopy(m_renderer, imagetoofan, NULL, &g_rect);

    g_rect.x = 650 + cosball * -63 - 26;
    g_rect.y = 430 - sinball * -63 - 26;
    g_rect.h = 50;
    g_rect.w = 50;
    if (tmp_ball_center == 0)
        SDL_RenderCopy(m_renderer, image0, NULL, &g_rect);
    else if (tmp_ball_center == 1)
        SDL_RenderCopy(m_renderer, image1, NULL, &g_rect);
    else if (tmp_ball_center == 2)
        SDL_RenderCopy(m_renderer, image2, NULL, &g_rect);
    else if (tmp_ball_center == 3)
        SDL_RenderCopy(m_renderer, image3, NULL, &g_rect);

    else if (tmp_ball_center == 4)
        SDL_RenderCopy(m_renderer, imagebomb, NULL, &g_rect);
    else if (tmp_ball_center == 5)
        SDL_RenderCopy(m_renderer, imageraed, NULL, &g_rect);
    else if (tmp_ball_center == 6)
        SDL_RenderCopy(m_renderer, imagechand, NULL, &g_rect);
    else if (tmp_ball_center == 7)
        SDL_RenderCopy(m_renderer, imagefire, NULL, &g_rect);
    else if (tmp_ball_center == 8)
        SDL_RenderCopy(m_renderer, imagetoofan, NULL, &g_rect);

    // Tools::ellipse(m_renderer,650 + cosball * 20,430 - sinball * 20,35,35,colors[ball_center][0],colors[ball_center][1],colors[ball_center][2],1);
    // Tools::ellipse(m_renderer,650 + cosball*-60,430 - sinball * -60,30,30,colors[tmp_ball_center][0],colors[tmp_ball_center][1],colors[tmp_ball_center][2],1);
}

void EndGame::confidentbox()
{

    Tools::texture(m_renderer, "pic/conf.png", 640, 400, 511 / 1.5, 282 / 1.5);
    Tools::texture(m_renderer, "pic/yes.png", 580, 450, 50 * scyes, 30 * scyes);
    Tools::texture(m_renderer, "pic/no.png", 710, 450, 50 * scno, 30 * scno);
}

// string player after login or register set mishw
