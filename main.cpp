#include <iostream>
#include <cstdlib>
#include <vector>
#include <raylib.h>




using namespace std;

int main()
{

    bool button1,button2,button3,button4,button5,button8;
    int buttonpressed;
    float joy1,joy2;

    vector<Vector2> buttons;
    buttons={{1006,940},{1031,966},{997,998},{960,970},{1375,828},{1411,878},{1361,905},{1319,858},{938,761},{0,0},{1368,768},
                {0,0},{1065,878},{1135,878},{1211,875},{910,884},{1271,959}};
    




    //SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(2000,2000,"Joystick Stuff");
    SetTargetFPS(60);
    InitAudioDevice();

    Font digital=LoadFontEx("./resources/digital-7.ttf",80,0,0);
        if (digital.texture.id==0)
            cout<<"Font not loaded...\n";

    Texture2D xbox=LoadTexture("./resources/xbox.png");
    Texture2D joy=LoadTexture("./resources/joystick.png");
    Texture2D joyshadow=LoadTexture("./resources/joyshadow.png");

    Sound zap=LoadSound("./resources/Laser.wav");


    while(!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(GRAY);

            DrawRectangle(0,GetScreenHeight()*.85,GetScreenWidth(),GetScreenHeight()*.15,BLACK);
            string gamepd = GetGamepadName(0);
            string title="Joystick Device: "+gamepd;
            DrawTextEx(digital,title.c_str(),{GetScreenWidth()*.1,GetScreenHeight()*.9},80,0,GREEN);
            DrawTextureEx(joyshadow,{GetScreenWidth()*.22,GetScreenHeight()*.25},0,1.3,WHITE);
            DrawTextureEx(xbox,{GetScreenWidth()*.2,GetScreenHeight()*.2},0,1.3,WHITE);
            

           // DrawTexture(xbox,GetScreenWidth()*.2,GetScreenHeight()*.2,WHITE);

           


            system("clear");
            buttonpressed=GetGamepadButtonPressed();
            cout<<"Button: "<<buttonpressed<<endl;
            

           
            cout<<"mousexy: "<<GetMousePosition().x<<" , "<<GetMousePosition().y<<endl;

            if (buttonpressed!=0)
            {
                string msgstr="Button "+to_string(buttonpressed);
                DrawCircleV(buttons[buttonpressed-1],25,Color{0,250,50,rand()*150+100});
                DrawTextEx(digital,msgstr.c_str(),{GetScreenWidth()*.4,GetScreenHeight()*.25},80,0,BLACK);
                DrawLineEx({GetScreenWidth()*.45,GetScreenHeight()*.3},buttons[buttonpressed-1],5,BLACK);

                //if(!IsSoundPlaying(zap))
                    PlaySound(zap);
            }

            float joyaxiscount=GetGamepadAxisCount(2);
            cout<<"joystick axis: "<<joyaxiscount<<endl;
//--------------------------------------
            bool moveflag=false;

            float axis1=GetGamepadAxisMovement(0,0);    //up/down
            float axis2=GetGamepadAxisMovement(0,1);    //left/right
            if(abs(axis1)<0.01) axis1=0;
            if(abs(axis2)<0.01) axis2=0;

            if (axis1==0 && axis2==0)
            {
                DrawCircle(910,884,35,Color{130,10,10,255});
                DrawCircle(910,884,20,Color{255,0,13,55});
                DrawCircle(925,870,5,WHITE);
                DrawCircle(930,885,2,WHITE);
            }
                    else
                    if (abs(axis1)>abs(axis2))
                        DrawTexturePro(joy,{0,0,joy.width,joy.height},{910,884,joy.width,joy.height},
                                {joy.width/2,joy.height/1.6},axis1*90,WHITE);
                                else
                                    DrawTexturePro(joy,{0,0,joy.width,joy.height},{910,884,joy.width,joy.height},
                                    {joy.width/2,joy.height/1.6},axis2*90+90,WHITE);



            float axis3=GetGamepadAxisMovement(0,2);
            float axis4=GetGamepadAxisMovement(0,3);
            if(abs(axis3)<0.01) axis3=0;
            if(abs(axis4)<0.01) axis4=0;

            if (axis3==0 && axis4==0)
                
                {
                    DrawCircle(1271,959,35,Color{130,10,10,255});
                    DrawCircle(1271,959,20,Color{255,0,13,55});
                    DrawCircle(1286,945,5,WHITE);
                    DrawCircle(1276,974,3,WHITE);
                }
                    else
                    if (abs(axis3)>abs(axis4))
                        DrawTexturePro(joy,{0,0,joy.width,joy.height},{1271,959,joy.width,joy.height},
                                {joy.width/2,joy.height/1.6},axis3*90,WHITE);
                                else
                                    DrawTexturePro(joy,{0,0,joy.width,joy.height},{1271,959,joy.width,joy.height},
                                    {joy.width/2,joy.height/1.6},axis4*90+90,WHITE);


            float axis5=GetGamepadAxisMovement(0,4);
            float axis6=GetGamepadAxisMovement(0,5);
            if(abs(axis5)<0.01) axis5=0;
            if(abs(axis6)<0.01) axis6=0;

            if(axis5>-1)
                    {
                        DrawTextEx(digital,"AXIS Trigger 5 LEFT",{GetScreenWidth()*.2,GetScreenHeight()*.2},
                                80,0,BLACK);
                        DrawLineEx({GetScreenWidth()*.3,GetScreenHeight()*.25},{938,761},8,BLACK);

                    }
            if(axis6>-1)
                    {
                        DrawTextEx(digital,"AXIS Trigger 6 RIGHT",{GetScreenWidth()*.6,GetScreenHeight()*.2},80,0,BLACK);
                        DrawLineEx({GetScreenWidth()*.7,GetScreenHeight()*.25},{1368,768},8,BLACK);

                    }




            cout<<"axis1 movement: "<<axis1*90<<endl;
            cout<<"axis2 movement: "<<axis2<<endl;
            cout<<"axis3 movement: "<<axis3<<endl;
            cout<<"axis4 movement: "<<axis4<<endl;
            cout<<"axis5 movement: "<<axis5<<endl;
            cout<<"axis6 movement: "<<axis6<<endl;

            
            
            

            
            
            






        EndDrawing();


    }




    cout<<"Unloading..."<<endl;

    UnloadFont(digital);
    UnloadTexture(xbox);
    UnloadTexture(joy);
    UnloadTexture(joyshadow);
    UnloadSound(zap);



    CloseAudioDevice();

    return 0;
    
}