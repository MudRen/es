#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "drink_water", "drink" );
}

void create()
{
        set_name( "Pool of Radiance", "��â֮��" );
        add( "id", ({ "pool" }) );
        set_short( "��â֮��" );
        set_long(@C_LONG
����һ��ɢ�������ع�â��С�أ�������ʮ�ֹ��죬���Ǵ�˵���ĳ�ˮ��
���������Ĺ�\Ч����(drink)�ȿ���
C_LONG
		);
   		set("unit","��");
   		set("weight", 100000);
}

int drink_water(string arg)
{
	if( !arg || arg != "water") return 0;
	write(
		"�����һ�ڳ�ˮ��ͻȻһ��ƣ�ۣ�����ȫ�������������Ǭ��...:)\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"�ӳ��к���һ��ˮ��Ȼ����ɫ����ת�ɲ԰�...\n"
		, this_player()
	);
		this_player()->set_heart_beat(1);
                this_player()->set("hit_points", 1);
	return 1;
}
