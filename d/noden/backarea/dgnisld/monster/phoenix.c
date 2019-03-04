#include <mudlib.h>

inherit MONSTER;

void create ()
{

  ::create();
   set_level(20);
	set_name( "Phoenix", "������" );
   add( "id", ({ "phoenix", "bird" }) );
   set_short( "������ԡ����" );
   set_long(
	    "������ԡ����ȫ���ǻ𡣾�˵ÿ����������������ɽ����\n"
	"�����»������������˵��������Ѫ���Գ���������\n"
	);
	
   set( "max_hp", 4000 );
   set( "max_sp", 4000 );
   set( "hit_points", 4000 );
   set( "spell_points", 4000 );
   set_natural_armor( 35, 35 );
   set_natural_weapon( 35, 30, 50 );
   set( "wealth/gold", 500 );
   set( "weight", 800 );
   set( "gender", "female" );
   set( "unit", "ֻ" );
   set( "exp_reward", 50000 );
   set( "immortal", 1 );
   set( "chat_chance", 10 );
   set( "chat_output", ({
	    "ԡ����˵����ɱ��û�õģ����ǲ����ġ�\n",
    }) );
}
