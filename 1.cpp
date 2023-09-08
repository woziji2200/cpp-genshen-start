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

void rgb_init() {                                   // ��ʼ��
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);    // ������
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // ������
    DWORD dwInMode, dwOutMode;
    GetConsoleMode(hIn, &dwInMode);    // ��ȡ����̨����ģʽ
    GetConsoleMode(hOut, &dwOutMode);  // ��ȡ����̨���ģʽ
    dwInMode |= 0x0200;                // ����
    dwOutMode |= 0x0004;
    SetConsoleMode(hIn, dwInMode);    // ���ÿ���̨����ģʽ
    SetConsoleMode(hOut, dwOutMode);  // ���ÿ���̨���ģʽ
}

void rgb_set(int wr, int wg, int wb, int br, int bg, int bb) {  // ����RGB
    printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm", wr, wg, wb, br, bg,
           bb);  //\033[38��ʾǰ����\033[48��ʾ����������%d��ʾ��ϵ���
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
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */

    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* ��ȡ������Ϣ */
    /* ���ô�����Ϣ ��� ȡ�����������߿� */
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
"                      @\\                                         ��������ﾯ��                                                        \n"
"                     @  \\                                                                                                             \n"
"                    @    @                �м����������ڹۿ�һЩ�Ӿ�Ӱ��ʱ���ܻ�ͻȻ��﷢������ЩӰ���������                           \n"
"                   @  @@  \\              ��Ϸ�г��ֵ������ͼ�Ρ�������û��ͻȻ���������ʷ����Ҳ���ܾ���һЩ                           \n"
"                 /    @@   @              ���ܻ��ڹۿ���Ƶ��Ϸʱ���¡���������﷢������δȷ��֢״�����֢����ʱ                           \n"
"                @     @@    @             �����ж���֢״������ͷ��Ŀѣ���۾����沿�鴤����֫���λ򷢶�����־��                           \n"
"               @             @            �塢���һ���ʱʧȥ��ʶ����﷢��Ҳ���ܵ�����ʶɥʧ���Σ��������ܵ���                         \n"
"              @       @@      \\          �����������ײ�����Աߵ���������ˡ����������������κ�֢״��������ֹͣ                         \n"
"             @                 \\         ����Ϸ����ҽ��ϡ�������Լ����������������ʷ�����ڽ�����Ϸ֮ǰ��ҽʦ                         \n"
"            [[[[[[[[[[[[[[[[[[[[[                                                                                                      \n"
"                                                                                                                                       \n"
"                                                                                                                                       \n"
"                                                                                                                                       \n"
"                    ����Ϸ��ʱ�䡢�ص㡢����¼������¼��������ݾ�Ϊ�鹹������ʵ�����ʱ���޹ء�������ͬ�������ɺϡ�                    \n";
        outnewline(11);

        Sleep(10);
    }
    Sleep(3000);
    color.cls();

    outnewline(9);
    outnewline(28);
    outnewline(8);
    outnewline(2);

    // cout << "�����ĺţ�gen";
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
                "���Ʋ�����Ϸ���ܾ�������Ϸ��ע�����ұ����������ϵ���ƭ���ʶ���"
                "Ϸ���ԣ�������Ϸ����������ʱ�䣬���ܽ�������             \n";
        cout << "            �����ĺ�:���³���[2019]2978�� ISBN 978-7-498-06905-4 ���浥λ:����ʦ����ѧ����������������޹�˾          \n";
        cout << "                                   ����Ȩ��:�Ϻ��׹��������Ƽ����޹�˾                                               \n";
        cout << "                                  ����˾�������С�������Ϸ��ҵ���������ɹ�Լ��                                       \n";

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
                "���Ʋ�����Ϸ���ܾ�������Ϸ��ע�����ұ����������ϵ���ƭ���ʶ���"
                "Ϸ���ԣ�������Ϸ����������ʱ�䣬���ܽ�������             \n";
        cout << "            �����ĺ�:���³���[2019]2978�� ISBN 978-7-498-06905-4 ���浥λ:����ʦ����ѧ����������������޹�˾          \n";
        cout << "                                   ����Ȩ��:�Ϻ��׹��������Ƽ����޹�˾                                               \n";
        cout << "                                  ����˾�������С�������Ϸ��ҵ���������ɹ�Լ��                                       \n";

        outnewline(2);
        Sleep(10);
    }
    Sleep(1000);
    color.cls();
    system("pause");

    return 0;
}