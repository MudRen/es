#include <mudlib.h>
#include <daemons.h>
#include <explore.h>

inherit WEAPON;

string C_NAME=("��Ȼ����");
void create()
{
        set_name( "Silent Whip",C_NAME );
        add( "id",({ "whip","silent whip"}) );
        set_short( C_NAME );
        set_long(@LONG
���ǳ��϶���ǰ�ڶ�������ʱ����䷢�ֵ��ı��ӣ���������������
��������������һ�����ص���������֪��˭�ܽ�����������ӳ���
LONG
                );
        set( "unit","��" );
        set( "type","whip" );
        set( "weapon_class",35 );
	set( "min_damage",17 );
	set ("max_damage",30 );
        set( "weight",90 );
        set( "value",({ 2300,"silver" }) );
        set( "wield_func","wi_func");
        set( "unwield_func","unwi_func");
}

void wi_func()
{
        int explore,allexp,power;
        explore = (int)this_player()->query_explore_points();
	allexp = (int)EXPLORE_D->query_total_explore();
	power = explore/allexp; // from 0% -- 100%
        set("min_damage",15 + power*10);
        set("max_damage",30 + power*10);
}

void unwi_func()
{
	set( "min_damage",15);
	set("max_damage", 30);
}

