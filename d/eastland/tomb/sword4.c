#include <almuhara.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("��ڣ");
	set_long( 
@C_LONG_DESCRIPTION
			��  ��ڣ  ��
             �㱻ӭ����������������ɷ���Ĵ�����ס !! 
�ò����׻ع�������ȴ�ֱ����ܵľ�������һ����������˶�Ľ�����춴ˣ��ѹָղŻ���
���ָо���ԭ������Щ��һ�𷢳���ɱ�⡢��������������ʴ�ǵĺ��⡣���ǲ�֪���Ѿ���
�����������ˣ�Ȼ��ÿ�ѽ����ɾ����������ݷ��ڲ��ʼ�į����˵�����ǻԻ͵Ĺ�ȥ����
ͥ����һ�������͵�ʯ��(stone)����֪���к���;��
C_LONG_DESCRIPTION
	);

	set( "light", 1);
	set( "OUT", 0);
	set( "exits", ([ 
		"north": TOMB"/sword6",
		"south": TOMB"/sword5",
		"east" : TOMB"/sword3",
		"west" : TOMB"/sword7"  ]) );
	create_door( "east","west",
		   (["keyword" : ({"door", "iron"}),
		     "name"    : "iron door",
		     "c_name"  : "������",
		     "desc"    : "A huge iron door\n",
		     "c_desc"  : "һ�ȼ�̵Ĵ����š�\n",		
		     "lock"    : "TOMBKEY_2",
		     "status"  : "locked",
		     ]) );
	add( "c_item_desc", ([
		"stone" :@STONE_DESC
�����ʯ�յ������߸���һ��С�ף�ǡ�ÿ�������һ�ѽ�����ϸ�����������ʯ����
��Լ����ĳ��������
STONE_DESC
	]) );	
	reset();	
}

void init()
{
	add_action("insert_sword","insert");
	add_action("unlock_door","unlock");
}

int insert_sword(string str)
{
	object player,obj;
	int seal;
	string sword,pos;
	
	player = this_player();
	seal = (int)player->query_temp("SEAL");
	if ( !str || str=="")
	return notify_fail("Syntax: insert <sword> into <position>.\n"
			   "Just type its name, no need the word 'sword'\n");
	if ( present( "sky guilt" , this_object() )  || (int)this_object()->query("OUT") == 1 ) return 1;
	if ( sscanf(str, "%s into %s", sword, pos) ) {
		if ( seal == 0 && sword == "gemmy" && pos == "center_right") {
			if ( !obj=present( "gemmy sword" , player ) )
				return notify_fail( "��û����ѽ���\n" );
			tell_room( this_object(),
				"\n"+"ʯ������һ�¡�\n" );
			player->set_temp("SEAL", 1);
			obj->remove();
			return 1; }
		else if ( seal == 1 && sword == "famous" && pos == "down_left" ) {
			if ( !obj=present( "famous sword" , player) )
				return notify_fail( "��û����ѽ���\n" );
			tell_room( this_object(), 
				"\n"+"һ���â�Է�ӡ�з���........\n"
				"������һ���º͵�����˵����Ϊ��Ԥ����а�����ѣ�������������ѽ����Ž���\n"
				"�Զ�����!!\n" );
			player->set_temp("SEAL", 2);
			obj->remove();
			return 1; }
		else if ( seal == 2 && sword == "antique" && pos == "up_left") {
			if ( !obj=present( "antique sword" , player) )
				return notify_fail( "��û����ѽ���\n" );
			tell_room( this_object(), 
				"\n"+"ͻȻһ�������ʯ���г����ͬʱ���������Զ��պϲ����ϵ�������\n" );
			obj->remove();
			new(MOB"/sky_guilt")->move(this_object());
                        this_player()->set_explore("eastland#35");
			set_status("east","locked");
			update_link("east");
			player->delete_temp("SEAL");
			this_object()->set("OUT",1);
			return 1; }
		else return notify_fail( "��Ҫ����??\n" ); 
	}
}		

int unlock_door()
{
	object player,ob;
	int chinese_mode;
	
	player = this_player();
	chinese_mode = can_read_chinese(player);
	
	if( present("cockroach", this_object()) ) {
		tell_room( this_object(), chinese_mode?
			"�����д棬�޷����� !!\n":
			"The monster is still alive, so can't unlock the door.\n" );
		return 1; }
	return 0;
}

