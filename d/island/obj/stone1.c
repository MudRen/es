#include <mudlib.h>

inherit OBJECT;

void create()
{
	seteuid( getuid() );
	set_name( "peace stone", "��ƽ���" );
	add( "id", ({ "stone" }) );
	set_short( "��ƽ���" );
	set_long(@LONG
�����ƽ�ļ�����������õ��������ͣ���������൱��Ȥ��
LONG
	);
	set( "unit", "��" );
	set( "prevent_get",1 );
}

void init()
{ 
	add_action( "do_beg", "beg" ); 
}

int do_beg(string arg)
{
	object obj,obj1,env,player;
	int i;
	string pname;

	env=environment(this_object());
	player=this_player();
	pname=player->query( "c_name" );

	if( !arg )
		return notify_fail( "������ʲ�ᣡ��\n" );

	if( arg == "holy_knight" )
	{
	if( (int)player->query_level()<=3 )
		return notify_fail( "СС��ͣ���Ҫѧ�����£�\n" );
		
	else
	{
	  if( !(obj=present("lizardman holy knight",env)) )
		return notify_fail("�˲����������\n");
	  	
	    if( (int)player->query_temp("jousting")==1 )
	    {
	      if( (int)(obj->query("no_jousting"))==0 )
	      {
//		obj1=new( IWEP"jousting" );
//		obj1->move( player );
		i=player->query( "max_tp" );
		player->set( "talk_points",i );
		player->force_me( "shout �Բ����Ҳ�С�İ�ս�������ˡ�����" );
		obj->set("no_jousting",1);
		write("\nʥ��ʿ��ʯ�����𽻸����㣬�ף�����ɴ�������ˣ�\n\n");
		tell_room(env,set_color(
		"\n�㿴��ʥ��ʿ���˫����������סʯ����ʯ����������̻�Ϊ��Ƭ��\n"+
		"����ʯ�������ͬʱ��һ��ҫ�۵Ĺ�â��ʥ��ʿ���Ϸ��������㼸���Ų����۾���\n"+
		"��������ʥ��ʿ˫�ֿ�ȥ���ף��ǲ����Ǵ�˵�еġ�������ꪡ���\n\n"+
		"����ʥ��ʿ���ꪽ�����"+pname+"\n","HIY"),player );
//		obj->command("go up");
		call_out("s_war",2);
		return 1;
		}
		
              else
              return notify_fail( "\nʥ��ʿ����˵������Ǹ������类�Ψ�����ˡ���\n\n" ); 
              }
              
          i=(int)( player->query("max_tp") );
	  player->set( "talk_points",i );
	  player->force_me( "shout ��Ҫ�������ɵ�����ս���ޣ���·Ӣ�ۺú���ս�������Ͱɣ� " );
	  tell_room( environment(player),set_color( 
	  "\nʥ��ʿ�������ƣ�������ʯ����һ�ģ�ʯ���ͻҷ�������\n","HIR" ) );
	  obj->leave();
	  call_out("s_war",2);
	  return 1;
	  }
	}
	else
	{
	write("��˭����\n");
	return 1;
	}
}

void s_war()
{
	find_object_or_load("/open/odin/island/war/islandwar")->start_war();
	remove();
}
