
#include "../goomay.h"

inherit Mob_special;

void create()
{
	
	::create();
	set_level(4);
	set_name( "mama", "����ɣ" );
	set_short( "����ɣ" );
	set_long(
	"һ��ȫ��Ǭ��ȴ���ú�*��¶*�������ţ��������տ������õ����⡣\n"
		 );
	set("alignment",100);
	set( "gender", "female" );
	set( "race", "halfling" );
	set( "unit", "��" );
	set_perm_stat( "str", 7 );
	set ("wealth", ([ "silver": 50 ]) );
	set_natural_weapon(4,4,9);
	set_natural_armor(26,0);
        set("special_attack",(["damage_type" : "energy","main_damage" : 6,
                                "random_dam" : 3 , "hit_rate" : 15]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg","����ɣ����С��ʳ���ͷ��һ������ ....ʹ����...\n\n");
set("c_room_msg","����ɣ��������С��ʳ�");
set("c_room_msg2", "һ���Ҵ򣬰��������ͷת�� ...\n");
        set( "chat_chance", 15 );
        set( "att_chat_output", ({
                "����ɣ��е�������С�� !! ���������Ҷ�Ҫ�۸� !! ����\n",
	}) );
}
