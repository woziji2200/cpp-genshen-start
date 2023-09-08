#include <stdio.h>

#include <cstring>
#include <iostream>
#include "Windows.h"
#include "Color.h"
#include "iomanip"
#include <tchar.h>
#include <MMSystem.h>
#pragma comment(lib,"WINMM.LIB")
using namespace std;

void rgb_init() {                                   // 初始化
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);    // 输入句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // 输出句柄
    DWORD dwInMode, dwOutMode;
    GetConsoleMode(hIn, &dwInMode);    // 获取控制台输入模式
    GetConsoleMode(hOut, &dwOutMode);  // 获取控制台输出模式
    dwInMode |= 0x0200;                // 更改
    dwOutMode |= 0x0004;
    SetConsoleMode(hIn, dwInMode);    // 设置控制台输入模式
    SetConsoleMode(hOut, dwOutMode);  // 设置控制台输出模式
}

void rgb_set(int wr, int wg, int wb, int br, int bg, int bb) {  // 设置RGB
    printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm", wr, wg, wb, br, bg,
           bb);  //\033[38表示前景，\033[48表示背景，三个%d表示混合的数
}

double mapValue(double value, double fromMin, double fromMax, double toMin, double toMax) {
    if (value < fromMin) {
        value = fromMin;
    }
    else if (value > fromMax) {
        value = fromMax;
    }
    double mappedValue = ((value - fromMin) / (fromMax - fromMin)) * (toMax - toMin) + toMin;
    return mappedValue;
}
void outnewline(int num){
    for(int i = 0; i < num; i++){
        rgb_set(0, 0, 0, 255, 255, 255);
        cout << "                                                                                                                                      \n";
    }
}

void full_screen() {   
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */

    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* 获取窗口信息 */
    /* 设置窗口信息 最大化 取消标题栏及边框 */
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}
int main() {


    full_screen();
    string genshen =
"                                                                                                                                      \n"
"                                                                                    @                                                 \n"
"                                                                                   .@`                                                \n"
"                                                                                   =@^                                                \n"
"                                                                                   /@\\                                                \n"
"                                   `                              ,`              ,@@@.                                               \n"
"                                  =@`                             /@.             /@@@\\                                               \n"
"                               .,/@@@\\`.                       ,]@@@@].         ,@@@@@@@` .                                           \n"
"                              .[@@@@@@@[[[[[[[[\\@@[[[[[[[[[[[[[[@@@@@@[`.     .[\\@@@@@@@/[.                                           \n"
"                                =@@@@@.,]. .  ,@@@@`  .]`        .@@`]@^  ,]`..   .@@@.   ,/]` .                                      \n"
"                                =@@@@@.@@@@@@@@@@@@@@@@@@@@`/@@@@@@@@@@@@`@@@@@@@@@@@@@@@@@@@@@@                                      \n"
"                                =@@@@@.@@@@@^        =@@@@^ =@@@^@@@@@@@@/@@@@@^  ,@@@`  =@@@@@                                       \n"
"                                =@@@@@.@@@@@@@@@@@@@\\=@@@@^ =@@@^@@@@.]]]`@@@@@\\@@@@@@@@@/@@@@@                                       \n"
"                                =@@@@@.@@@@@^        =@@@@^ =@@@^@@@@=@@@^@@@@@^[@@@@@@@[=@@@@@                                       \n"
"                                =@@@@/ @@@@@@@@@@@@@@@@@@@^ =@@@^@@@@=@@@^@@@@@^  .@@@.  =@@@@/                                       \n"
"                                =@@@@` \\/[..  =@@@@^ ,[[..  =@@@^@@@@=@@@.@@@@@@@@@@@@@@@@@@@@^                                       \n"
"                               ,@@@@`.]@@@@@\\ =@@@@^ /@@@@@]=@@@`@@@@=@` .@@@@`   ,@@@`   ,@@@^                                       \n"
"                              ,@@@/,@@@@@@@@[[=@@@@^[[@@@@@@@@@` @@@@.        .]/@@@@@@@\\].   .                                       \n"
"                             =@@` . ,@@]      =@@@@^     ./@@`   @@@@.         .[@@@@@@@/.                                            \n"
"                           .,.          ..[`  =@@@^  .,[..       @@@^            .@@@@@                                               \n"
"                                              =@`                @[ .             =@@@^                                               \n"
"                                                                                  .@@@.                                               \n"
"                                                                                   =@^                                                \n"
"                                                                                   =@^                                                \n"
"                                                                                   .@^                                                \n"
"                                                                                   .@.                                                \n"
"                                                                                    @                                                 \n"
"                                                                                                                                      \n";
    rgb_init();
    Color color;
    color.cls();
    system("cls");
    system("color 70");
    outnewline(37);
    mciSendString(_T("open genshit.mp3 alias bkmusic"), NULL, 0, NULL);
    mciSendString(_T("play bkmusic"), NULL, 0, NULL);
    Sleep(10000);

    for (int i = 255; i > 1; i = i - 4) {
        color.cls();
        outnewline(9);
        rgb_set(i, i, i, 255, 255, 255);
        cout << 
"                                                                                                                                        \n"
"                      @\\                                         光敏性癫痫警告                                                        \n"
"                     @  \\                                                                                                             \n"
"                    @    @                有极少数的人在观看一些视觉影像时可能会突然癫痫发作，这些影响包括电玩                           \n"
"                   @  @@  \\              游戏中出现的闪光或图形。甚至连没有突然发病或癫痫史的人也可能具有一些                           \n"
"                 /    @@   @              可能会在观看视频游戏时导致“光敏性癫痫发作”的未确诊症状。癫痫症发作时                           \n"
"                @     @@    @             可能有多种症状，包括头晕目眩、眼睛或面部抽搐、四肢痉挛或发抖、神志不                           \n"
"               @             @            清、混乱或暂时失去意识。癫痫发作也可能导致意识丧失或痉挛，进而可能导致                         \n"
"              @       @@      \\          患者因跌倒或撞击到旁边的物体而受伤。若出现以上所述任何症状，请立即停止                         \n"
"             @                 \\         该游戏并送医诊断。如果您自己或您的亲友有癫痫史，请在进行游戏之前与医师                         \n"
"            [[[[[[[[[[[[[[[[[[[[[                                                                                                      \n"
"                                                                                                                                       \n"
"                                                                                                                                       \n"
"                                                                                                                                       \n"
"                    本游戏的时间、地点、人物、事件、故事及其他内容均为虚构，与真实人物或时间无关。如有雷同，纯属巧合。                    \n";
        outnewline(11);

        Sleep(10);
    }
    Sleep(3000);
    color.cls();

    outnewline(9);
    outnewline(28);
    outnewline(8);
    outnewline(2);

    // cout << "审批文号：gen";
    Sleep(500);
    for (int i = 255; i > 1; i = i - 2) {
        color.cls();
        outnewline(9);
        rgb_set(i, i, i, 255, 255, 255);
        cout << genshen;
        rgb_set(0, 0, 0, 255, 255, 255);
        outnewline(5);
        int i2 = i < 255 - 80 ? mapValue(i - 80, 0, 255-80, 0, 255) : 255;
        // cout<<i2<<"  "<<endl;
        rgb_set(i2, i2, i2, 255, 255, 255);
        cout << "           "
                "抵制不良游戏，拒绝盗版游戏，注意自我保护，谨防上当受骗。适度游"
                "戏宜脑，沉迷游戏伤身，合理安排时间，享受健康生活             \n";
        cout << "            审批文号:国新出审[2019]2978号 ISBN 978-7-498-06905-4 出版单位:华东师范大学电子音像出版社有限公司          \n";
        cout << "                                   著作权人:上海米哈游天命科技有限公司                                               \n";
        cout << "                                  本公司积极履行《网络游戏行业防沉迷自律公约》                                       \n";

        rgb_set(0, 0, 0, 255, 255, 255);
        outnewline(2);
        Sleep(10);
    }
    Sleep(6000);
    for (int i = 0; i < 255; i = i + 2) {
        color.cls();
        outnewline(9);
        rgb_set(i, i, i, 255, 255, 255);
        cout << genshen;
        rgb_set(0, 0, 0, 255, 255, 255);
        outnewline(5);
        cout << "           "
                "抵制不良游戏，拒绝盗版游戏，注意自我保护，谨防上当受骗。适度游"
                "戏宜脑，沉迷游戏伤身，合理安排时间，享受健康生活             \n";
        cout << "            审批文号:国新出审[2019]2978号 ISBN 978-7-498-06905-4 出版单位:华东师范大学电子音像出版社有限公司          \n";
        cout << "                                   著作权人:上海米哈游天命科技有限公司                                               \n";
        cout << "                                  本公司积极履行《网络游戏行业防沉迷自律公约》                                       \n";

        outnewline(2);
        Sleep(10);
    }
    Sleep(1000);
    color.cls();
    system("pause");

    return 0;
}