//key issue of lizard_quest, modify it more easy, by Tsunami '96/09/15
#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "Сˮ����" );
	set_long(@LONG
�㳡��������������ƾ�����Сˮ�أ��ɾ��ĵ�̵�ˮ�����ɣ�
һ��������С��ˮ����ͷ���ѷ����£�Ϊ��������Ķ�Ѩ�����ٵ�
ɫ�ʡ�	
LONG
		);
	set( "light",1 );
	set( "exits",([
			"east"  : HOLE"hole27",
			"west"  : HOLE"hole21",
			"south" : HOLE"hole25",
			"north" : HOLE"hole23"
			]) );
	set( "objects",([
			"girl#1" : HMONSTER"girl",
			"girl#2" : HMONSTER"girl",
			]) );
	set( "item_desc",([
	"pool" : "ˮ���������ӳ����ĵ�Ӱ������Ⱥ�(drink)��ߵ�ˮ��\n" ]) );
	set( "water_source",1 );
	seteuid( geteuid() );
	reset();
}

void init(){ add_action( "to_drink","drink" ); }

int to_drink(string str)
{
	string him;
	object player, ob;
	int max;

	player=this_player();
	him=player->query( "c_name" );
	max=player->query( "max_tp" );
	if( !str || str=="" )
		return notify_fail( "�����ʲ�᣿\n" );
	if( str=="water" ){
	  if( player->query_temp("lizard_quest/get_saw")){
	  tell_room( environment(),set_color(
	  him+"��������ȿ�ˮ������Ż���һ�£�һͷ��ر�ˮ��ǽײȥ...��\n","HIR" ),
	  player);
	  write("����������ȿ�ˮ��ȴ����������һͷײ��ǽ�ڣ���ǽ��ҧ��һ��...\n");
          ob = new(HOBJ"amethyst");
          ob->move(player); 
          player->set_explore("island#9");
          }else{
	  tell_room( environment(player),set_color(
	  him+"������������һ�ڳ������ˮ���㷢��"+him+"�������������Ҹ��ı��顣\n","HIY" ),player );
	  tell_object(player,set_color(
	  "�����һ�ڳ������ˮ�ᣬ��ʱ���ú�ͷһ����ˬ��ͻȻ��󺰼�����\n","HIY" ) );
//	seteuid(geteuid(player));
//	player->force_me( "shout test....\n" );
	  }
	  return 1;
        }
        return notify_fail("�㵽����Ҫ��ʲ�᣿\n");
}
