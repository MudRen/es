
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Blacksword��Ya��Sha", "��ҹ��" );
        add( "id",({ "sword" }) );
        set_short( "Blacksword��Ya��Sha", "��ҹ��" );
        set_long("this is a black blade.\n",
            " ����һ�ѽ����ںڣ������ұ�����������Ҳ����ʿ���ӳ��ǣ߿��İ���\n"
        );
        set( "unit", "��");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 40 );
        set( "nosecond",0);
        set( "weight", 170 );
        set( "value", ({ 150, "gold" }) );
}


