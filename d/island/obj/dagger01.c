
#include <mudlib.h>
inherit WEAPON;

void create()
{
#include <compress_obj.h>
        set_name( "golden dagger","������" );
        add( "id",({ "dagger","daggercheck" }) );
        set_short( "������" );
        set_long(@C_LONG
����Ǯ�δ���ר�õı��꣬��˵Ǯ�δ���ÿɱһ���ˣ��ͻ��ڱ��������
��ɫ��ӣ�������ڱ�����ձ��Ѿ�������ɫ�Ļ��䣬ʵ��̫Ѫ���ˡ�       
C_LONG
        );
        set( "unit", "��");
        set( "weapon_class", 39);
        set( "type", "dagger" );
        set( "min_damage", 27 );
        set( "max_damage", 35 );
        set( "weight", 40 );
        set( "value", ({ 150, "gold" }) );
        set( "second" , 0 );
}

