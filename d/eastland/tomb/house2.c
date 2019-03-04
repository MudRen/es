#include <almuhara.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("����");
	set_long( 
@C_LONG_DESCRIPTION
����һ��������൱Ǭ���Ĵ�����������Щ���������ɵļҾߣ������������˾����൱
��ʵ���š�������һ�ɵ��������㣬���㾫��Ϊ֮һ����������һ��СС�Ĺ��������ϼ�
����һ����ʿ����֪���Ǻη���ʥ�����ǽ�Ϲ���һ�ѽ����ұ�����һ���ܴ�ıڻ�������
����һЩ��ֵ����ּ����ţ�����һ��������������������
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/house4",
		"south" : TOMB"/house3", 
		"out"   : TOMB"/house1" ]) );
	create_door( "out","enter",
		(["keyword" : ({"door"}),
		  "name"    : "red door",
		  "c_name"  : "����",
		  "c_desc"  : "һ�Ⱥ�ɫ���š�",
		  "status"  : "closed",
		  ]) );
	set( "objects", ([
		"boy#1" : MOB"/good_boy",
		"boy#2" : MOB"/evil_boy" ]) );
	set( "pre_exit_func", ([
		"south" : "check_boy" ]) );
	reset();	
}

int check_boy()
{
	object player;
	
	player = this_player();
	if( present("broken jade",player) ) {
		write( "Сͯ���˿������ϵ������壬˵�� : �� ���������Ҽ�Ů���˵�ร��������\n" );
		return 0; }
	if( present("old scroll",player) ) {
		write( "Сͯ���˿������ϵĻ��ᣬ˵�� : �� ���������Ҽ�Ů���˵�ร��������\n" );
		return 0; }
	if ( !wizardp(player) && present( "boy", this_object() ) ) {
		write( "Сͯ˵�� : �� ι !! �����˶�������ò�� ?? ����������˼ҵ����Ҵ� !! ��\n" );
	return 1; 
	} else return 0;	
}
