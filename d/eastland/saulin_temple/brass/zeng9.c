#include <almuhara.h>
#define SLAB_FILE "/d/eastland/data/brassman.txt"

inherit ROOM;

void create()
{
        ::create();
        set_short( "ͭ������" );
        set_long(
@C_LONG
�������һ������ʯ�ң������ǰ�漸��ʯ��Ψһ��ͬ���ǣ���
Ȼû��ͭ�������� !! ������ǰ����һ���޴��ͭ��¯(censer)������
�İ����ڿռ��и����������˾���һ�������������б��йŹ֣�����
���������ú������....
C_LONG
        );

	set( "time",0);
        set( "light",1 );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        set( "post_exit_func", ([
        	"north" : "post_north" ]) );
        add( "item_desc", ([
        	"censer" :
"����һ���޴����¯�����������޺���������֮�����Ȼ�뵽��
Сʱ���ӡ���У����ͭ�������Ҫ�Ὺ(move)����¯�...\n"
	]) );
        reset();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_quit","quit");
	add_action("do_auction","auction");
	add_action("do_songin","songin");
	add_action("do_move","move");
}

void announce( string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], c_msg);
	}
}

int do_knock(string str)
{
	object obj,ob1;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( str == "wall" ) {
		tell_object(obj,
			"ͻȻ���������޺���ǽ�а����߳�������̧�˳�ȥ��\n" );
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("�㿴�����������޺���%s��̧��һ��̧�˳�����\n",
				obj->query("c_name") ) );
		this_object()->set("time",0);
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1; }
	else return 0;
}
		
int do_quit()
{
	object obj,ob1;
	obj = this_player();
	
	tell_object(obj,
			"ͻȻ���������޺���ǽ�а����߳�������̧�˳�ȥ��\n" );
	ob1=find_object_or_load(SAULIN"/entrance");
	tell_room(ob1,
		sprintf("�㿴�����������޺���%s��̧��һ��̧�˳�����\n",
			obj->query("c_name") ) );
		this_object()->set("time",0);
		obj->add("monk_score",-100);
		obj->move_player(SAULIN"/entrance","SNEAK");
		ob1->set("enter",0);
		return 1;
}

int do_auction()
{
	return 1;
}

int do_songin()
{
	object obj;
	obj = this_player();
	if( !query_temp("alignment") ) {
		set_temp("alignment",obj->query("alignment"));
		return 0; }
	if( obj->query("alignment") > 10000 ) {
		this_object()->add("time",1);
		if( (int)this_object()->query("time") > (4+random(3)) ) {
			new("/d/eastland/saulin_temple/brass/obj/brassman6")->move(this_object());
			new("/d/eastland/saulin_temple/brass/obj/brassman7")->move(this_object());
			new("/d/eastland/saulin_temple/brass/obj/brassman8")->move(this_object());
			return 1; }
		return 0; }		
	else if( ((int)obj->query("alignment")-(int)query_temp("alignment")) > 500 ) {
		new("/d/eastland/saulin_temple/brass/obj/brassman6")->move(this_object());
		new("/d/eastland/saulin_temple/brass/obj/brassman7")->move(this_object());
		new("/d/eastland/saulin_temple/brass/obj/brassman8")->move(this_object());
		return 1; }
	else return 0;
}
	
int do_move(string str)
{
	object obj,ob1;
	string fame;
	seteuid(getuid());
	obj = this_player();
	
	if( !str || str == "" ) return 1;
	
	if( str == "censer" ) {
		if ( !obj->query_temp("be_k") ) {
			tell_object(obj,
				 "��� !! ���������᲻����Ү��\n");
			return 1; }
		tell_object(obj,
			"��ʹ��ȥ�ᶯ��¯����Ȼһ��������������ͳ�ȥ !!\n" );
		announce(
set_color("\nͻȻ�������·�������������������\n"
"\nͭ�����ϻ�Ԫ���������� ���� "+obj->query("c_name")+" ˳��ͨ��ʮ��ͭ�����\n"
"���� ����\n\n","HIB") );
		this_object()->set("time",0);
		obj->set("18brass",1);
		obj->move_player(SAULIN"/entrance","SNEAK");
		fame = "     "+(string)this_player()->query("c_name")+"("+
		(string)this_player()->query("name")+")"+" � "+
		"/adm/daemons/weather_d"->query_c_game_time()+" ���� !!\n";
		write_file(SLAB_FILE, fame+"\n");
		ob1=find_object_or_load(SAULIN"/entrance");
		tell_room(ob1,
			sprintf("�㿴��%s��ҡ��ڵ����˳�����һ���ܳ�ƨ�����ӡ�\n",
			obj->query("c_name") ),obj );
		ob1->set("enter",0);
		reset();
		return 1; }
	return 1;
}
