
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("front","ǰͥ�㳡");
       set_long(@C_LONG
����������£����ŵ�һ�ɵ�����ľ����ζ�����ܿ��
����ˮ����������ע�⵽ǰ����һ���󹬵����һ춵���
�ϸߣ������Ӳ����С��������ͥ����ٽ����ͥ����
������һ�ȿ�����ʯ�ţ���ڵĵص���֪ͨ���δ���
C_LONG );
       set("exits",([
                     "northwest":"/d/noden/drow/r65",
                     "eastdown":"/d/noden/drow/r71",
                    ]));
       set("pre_exit_func",([
                     "eastdown":"check_knight"]));
       set("light",1);
       set("object",([
                      "skeleton":"/d/noden/drow/mob/m30",
                   ]));
}
