
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Samurai��short��dagger", "��ʿ����" );
        add( "id",({ "dagger" }) );
        set_short( "Samuria��short��dagger", "��ʿ����" );
        set_long("this is a short dagger with great power .\n",
            "����һ�ѷ�����С��ذ�ף���Ȼ��ذ�����С��ȴ���������ƻ���\n"
        );
        set( "unit", "��");
        set( "weapon_class", 27 );
        set( "type", "dagger" );
        set( "min_damage", 13 );
        set( "max_damage", 28 );
        set( "weight", 50 );
        set( "value", ({ 100, "gold" }) );
}


