#include <saulin_temple.h>
#define SLAB_FILE "/d/eastland/data/brassman.txt"

inherit ROOM;

void create()
{
        ::create();
        set_short( "ͭ�������" );
        set_long(
@C_LONG
�������������������������µ�ͭ����ǰ�������������Ϊ�˲������µ�
���Ƿ�߱����㹻������ȥ������а���������壬�����õ��������ܹ�ͨ����
����������ֵ��Ӷ�����ͬ٭�е�ٮٮ�ߣ���������������£������������
����Ī������ͨ��ͭ����Ϊ������ҫ����ȻҲ��Щ������Ϊ�����������뻹
�ף���ʱ���ֵĳ����Ǿͻ���ͨ��ͭ����������������Ƿ���Ի��ס��㿴
���Ա����˿�ʯ��(slab)��������Щ�֡�
C_LONG
        );
 	set_outside("eastland");
 	set( "enter", 0);
        set( "exits", ([
        	"east" : SAULIN"stone_path3",
                "south" : SAULIN"grass2",
                "west" : SAULIN"grass0"
        ]) );
        set( "item_desc", ([
        	"slab" : "@@read_slab" ]) );
        set( "objects", ([
        	"elder#1" : "/d/eastland/saulin_temple/brass/obj/elder" ]) );
}

void init() 
{
	add_action("do_answer", "answer");
}

int do_answer(string str)
{
	object obj;
	obj = this_player();
	
	if( !str || str == "" ) return 0;
	if( !obj->query_temp("brassman") ) return 0;
	
	if( str == "yes" ) {
		if( this_object()->query("enter") ) {
			tell_object(obj,
				"��Ԫ��ʦ��������ţ�˵�����Ѿ����˽���ͭ�����ˡ�\n" );
			return 1; };
		if( (int)obj->query("monk_score") < 3600 ) {
			tell_object(obj,
				"��Ԫ��ʦ˵������������µĹ��ײ��������ý��롣\n" );
			return 1; };
	 	if( (string)obj->query("class") != "monk" ) {
			tell_object(obj,
				"��Ԫ��ʦ��������ţ�˵���������صأ�ʩ����������\n" );
			return 1; };
		if( (int)obj->query_level() < 14 ) {
			tell_object(obj,
				"��Ԫ��ʦ��������ţ�˵�������������㣬���ǲ�Ҫ����ð�հɡ�\n" );
			return 1; };
		if( (int)obj->query("18brass") ) {
			tell_object(obj,
				"��Ԫ��ʦ˵��������ͨ�������ˡ�\n" );
			return 1; };
		tell_object(obj,
			"��Ԫ��ʦ˵���������ӷ�ͭ������ز��ף����������������֧�Ļ�\n"
			"	      ���Ի���(knock wall)Ϊ�ţ���Ȼ���˻���������ǧ\n"
			"	      ��Ҫ��ǿ������׼��һ�°� !!\n" );
		obj->set_temp("block_command",1);
		call_out("enter_brass",4,this_player());
		return 1;
		}
	else return 0;
}

int enter_brass(object who) 
{
	tell_object(who,
			"��Ԫ��ʦ����һ�����ţ��������˽�ȥ��\n" );
	who->delete_temp("block_command");
	who->move_player(SAULIN"brass/zeng1","SNEAK");
	this_object()->set("enter",1); 
	return 1;}

int clean_up() { return 0; }

string read_slab()
{
	this_player()->more(SLAB_FILE);
	return "\n";
}
