//#pragma save_binary

// adding room desc, yeah.. run on sentences.. big deal.. -Elon 03-10-94
#include "moyada.h"
#define ant_number 4

inherit ROOM;

int ant = 0;

void create()
{
	::create();
	set( "dig", 1);
   set_short( "һƬɳ��" );
	set_long( @LONG_DESCRIPTION
������һƬ����ɳ�أ���ǰ������һ���޴��ɳ���㿴����ֻ��������
�����ģ�Ī����һ������(anthill)?
LONG_DESCRIPTION
	);
	set( "exits", ([
		"east" : MOYADA"mainrd7"
	]) );
	set( "c_item_desc", ([
		"anthill" : "һ����Сɽ����ڣ������ò�Ҫ��̫���������ܵ�����Χ����\n"+
		            "��������������С������Ⱥӵ���ϡ�\n",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant fighter" : MOYADA"monster/ant_fighter",
	   "ant solider" : MOYADA"monster/ant_solider",
	   "ant knight" : MOYADA"monster/ant_knight",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set( "ant_left", 10);
    ant = 0;
}

void init()
{
	add_action( "do_enter", "enter" );
}

void to_find_dig(string arg)
{
	object obj;
	int i;

	if( arg != "anthill" ) {
	write( "����û�����ֶ������ڣ�\n" );
	  return;
	}

	if( ant ) {
		write( "�����Ѩ�Ѿ����ڹ��ˣ�\n" );
		return;
	}

   write(
          "���ò���ȥ����ڣ�����һ����ڣ���ˣ�¶��һ����(hole)��\n" );
    tell_room( this_object(),
	this_player()->query("c_name")+"�ò���ȥ����Ѩ�����һ����ڣ���ˣ�\n",
		this_player() );
	add( "c_item_desc", ([
		"hole" : "��ڣ����ڣ�����ò�Ҫ���룬�����ܵ�����Χ����\n",
	]) );
	ant = 1;
	for( i=0; i<ant_number; i++ ) {
		obj = new( MOYADA"monster/ant_killer" );
		obj->move(this_object());
	}
   this_player()->set_explore("noden#7");
	return ;
}

int do_enter( string str )
{
    object obj, player;
    int left, i;
    if( !str || str == "" )
    return notify_fail( "��ȥ����?\n" );
    if( !ant )
       return notify_fail( "����û�ж���\n" );
    player = this_player();
    if( obj=present("ant") ) {
       tell_object( player,
          "���ڵ�������ֹ����벢��ʼ�����㡣\n" );
       obj->kill_ob( player );
       return 1;
     }
    if( (left=(int)this_object()->query("ant_left")) && (left>1) ) {
        tell_object( player, 
           "��ֻ���ϴ���ڣ�����˳����������ȥ����ʼ�����㡣\n" );
       for( i==0; i<2; i++ ) {
         obj = new(MOYADA"monster/ant_worker");
         obj->move(this_object());
         obj->kill_ob(player);
         left--;
       }
       this_object()->set("ant_left",left);
       return 1;
    }
     tell_room( MOYADA"anthill/cellar1", 
        sprintf("%s���˽�����\n", player->query("c_name") ), player );
     tell_room( this_object(),
       sprintf("%s������ڣ��\n", player->query("c_name") ), player );
    player->move_player(MOYADA"anthill/entrance","SNEAK");
    return 1;
}
