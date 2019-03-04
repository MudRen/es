#include "irc.h"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Midair","�����" );
    set_long( @LONG
LONG
	,@C_LONG
C_LONG
    );
}
 
void init()
{
    write(can_read_chinese()?
		"\nWeeeeeeeeeeeeee..............\n"+
		"�㿴������СС����, ���������ӽ���...\n"+
		"wowowowowowow.....\nԽ��Խ����!!!\n"+
		"WHAM!!!!!\nͻȻ�㱻һ��������ס��ͣ��������\n":
		"\nWeeeeeeeeee......\n"+
		"You see little trees and rivers below you...\n"+
		"wowowowowowow...\nIt's getting closer!!!\n"+
		"WHAM!\nThe sudden stop almost tear you into half.\n");
    call_out("hanging", 10, this_player());
    add_action("look_here","look");
}
 
int look_here(string str)
{
    if( str ) return 0;
    write(can_read_chinese()?
        "\n�����¿�, ����ɫ�ĺ�ˮ���ٵ������ȵס����Ͽ�, �������㻹��\n"+
        "һ�ξ��롣��... ���ڡ��ҡ��ڰ���С�\n":
        "\nYou are hanging in mid-air. Above you is the cliff and below\n"+
        "you, the dark blue river runs through the valley.\n"
    );
    return 1;
}
 
void hanging(object player)
{
	if( !player ) return;
    tell_object(player, can_read_chinese(player)?
    	"������㡸�ҡ�������̫��, ����ȥ��.... \n":
    	"You think you are here long enough, time to climb back!\n"
   	);
    tell_object( player, can_read_chinese(player)?
    	"��ץ������˳���±�������ȥ��\n":
    	"You climb up along the cliff wall.\n"
   	);
    player->move_player(IRC"deck_3.c","SNEAK");
    tell_room(environment(this_player()),({
    	player->query("cap_name")+" climbs up.\n",
    	player->query("c_cap_name")+"����������������\n" }),player
    );
    find_object(IRC"deck_3")->set("busy",0);
}

