#include "../island.h"

inherit OBJECT;
int announce(object ppl);

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
	string pname;

	env=environment(this_object());
	player=this_player();
	pname=player->query( "c_name" );

	if( !arg )
		return notify_fail( "������ʲ�ᣡ��\n" );

	if( arg != "Lizardman Holy Knight" )
		return notify_fail( "��˭����\n" );

	if( (int)player->query_level()<=5 )
		return notify_fail( "СС��ͣ���Ҫѧ�����£�\n" );

	if( !(obj=present("lizardman holy knight",env)) )
		return notify_fail("��������˲����������\n");

	if( (int)player->query_temp("jousting")==1 ) {
		if( (int)(obj->query("no_jousting"))==0 ) {
			obj1=new( IWEP"jousting" );
			obj1->move( player );
			obj->set("no_jousting",1);
			write("\nʥ��ʿ��ʯ�����𽻸����㣬�ף�����ɡ�������ꪡ��ˣ�\n\n");
			tell_room(env,set_color("\n�㿴��ʥ��ʿ���˫����������סʯ����ʯ����������̻�Ϊ��Ƭ��\n����ʯ�������ͬʱ��һ��ҫ�۵Ĺ�â��ʥ��ʿ���Ϸ��������㼸���Ų����۾���\n��������ʥ��ʿ˫�ֿ�ȥ���ף��ǲ����Ǵ�˵�еġ�������ꪡ���\n����ʥ��ʿ���ꪽ�����"+pname+"\n","HIY"),player );
		}
		else {
			player->set_temp("jousting",0);
			player->set_temp("holy_knight",0);
			write("\nʥ��ʿ����˵������Ǹ������类ȡ���ˡ���\n\n" );
		}
	}
	player->set_temp("jousting",0);
	player->set_temp("holy_knight",0);
	player->set( "talk_points",50 );
	announce(player);
	tell_room( environment(player),set_color(
	"\nʥ��ʿ�������ƣ�������ʯ����һ�ģ�ʯ���ͻҷ������ˡ�\n","HIR" ) );
	obj->leave();
	call_out("s_war",2);
	return 1;
}

void s_war()
{
	find_object_or_load(IWAR"islandwar")->start_war();
	remove();
}

int announce(object ppl)
{
	string class1,cname,name,cclass;
	object *usr;
	int i;

	usr=users();
	cname=ppl->query("c_name");
	name=ppl->query("name");
	class1=ppl->query("class");
	if (class1=="knight") { cclass="����ʿ��";}
	else if (class1=="healer") { cclass="����ҽ�ߡ�";}
	else if (class1=="scholar") { cclass="��������";}
	else if (class1=="monk") { cclass="����ɮ��";}
	else if (class1=="mage") { cclass="��ħ��ʦ��";}
	else if (class1=="thief") { cclass="��С͵��";}
	else { cclass="ĳ��";}

	for(i=sizeof(usr)-1;i>=0;i--) {
	tell_object(usr[i],set_color("Զ������"+cname+"("+name+")���ź� :","HIR")+"��Ҫ����ժ�ɵ�ս���ˣ�Ϊ�� "+set_color(cclass,"HIW")+" ������\n������һ�������ģ��Ǻ�.....\n*"+cname+"����¶�����ص�Ц��*\n");
	}
	return 1;
}
