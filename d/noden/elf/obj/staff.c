
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "elven staff", "������");
        add ("id",({ "staff" }) );
        set_short( "������" );
        set_long(
            "���Ǿ��鳤����ʹ�õ���������Ȼ��������������û��ħ�������⹥��\n"
            "������ǲɼ����ľ��������Դ�ұ���ɵ��������ʼ�Ӳ�쳣�ǲ����\n"
            "���������� \n" );
        set( "weapon_class", 20 );
        set( "min_damage", 10);
        set( "unit","��");
        set( "max_damage", 18);
        set( "type", "blunt");
        set( "weight", 90 );
        set( "value", ({ 400, "silver" }) );
}

