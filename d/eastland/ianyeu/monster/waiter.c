#include "../mad.h"

inherit MONSTER;
inherit "/std/seller";
void create()
{
	::create();
	set_level(6);
   set_name( "waiter", "��С��" );
   set_short( "��С��" );
	set_long(
        "�㿴��һ�����΢Ц, �����к���������(sit down)�ĵ�С����\n"
	);
	set( "race", "halfling" );
	set( "gender", "male" );
   set( "exp_reward", 111 );
// ���õ�״̬:P
   set( "wealth/copper", 10 );
	set_inventory( ({
           ({ IANOBJ"lamb", 10, 10 }),
           ({ IANOBJ"tea", 10, 10 }),
	}) );
}

void init()
{
	npc::init();
	seller::init();
}
