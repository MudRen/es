
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "magic staff", "����");
        add ("id",({ "staff" }) );
        set_short( "����");
        set_long(
            "���ǵؾ�����ʹ�õ���������������������û��ħ�������⹥����\n"
            "���������������ʹ���乥������һ��ǿ�ȡ� \n" );
        set( "weapon_class", 25 );
        set( "min_damage", 14);
        set( "unit","��");
        set( "max_damage", 20);
        set( "type", "blunt");
        set( "weight", 90 );
        set( "value", ({ 400, "silver" }) );
}

