#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("fighter's dagger","սʿ��ذ");
    add("id",({"dagger"}) );
    set_short("սʿ��ذ");
    set_long(@C_LONG
һ��������������ǧ�꾫�������겻������������ɵ��������ʺ�ɫ���󣬶�ʯ��
���������࣬�ط����쳣��
C_LONG
       );
    set("unit","��");
    setup_weapon( "dagger", 20, 13, 23 );
    set("weight",60);
    set("value",({60,"gold"}));
}
