#include "/d/mage/mage.h"
 
#define TMP_FILE "/tmp/wall."+getoid(this_player())
#define WALL_FILE "/d/mage/data/wall.txt"
 
inherit ROOM;
 
 
 
int process();
 
void create()
{
	
	::create();
	
	set_short("ħ��ʦ����������");
	
	set_long(@TEXT
�����������ĵ�����. ������һƬͿѻǽ (wall). ��ǰ�����˼���ʯ��. (slab)
����ǽ���˸����� (sign). ������д�˼�������:
 
���ϴ󵽴�һ��!
 
 
TEXT
	);
	
	set("item_desc", ([
	"sign" : @SIGN

��������������������������������������������������������������������
�� ħ��ʦ����������:                                              ��
�� 0. �������εĸ�������boss                                      ��
�� 1. Ҫ������������,����˵������(����ĳ��ħ����һ��������)       ��
�� 2. Ҫ��Ϳѻǽд�ֵ�: write wall                                ��
��������������������������������������������������������������������
 
������һ��С��: Jdw ��Ҫ������ med ��..
SIGN
	,
	"slab" : @SLAB

                �   ��������������������
                �   ��      boss      ��
                �   ��  (����ʿʿ)    ��
                �   ��     �          ��
                �   ��      ħ�       ��
                �   ��      ���       ��
                �   ��      ���       ��
                �   ��      ��        ��
                    ��      ��        ��
                �   ��      ��        ��
                �   ��      ��        ��
                    ����׼��������ְȨ��
                �   ��������������������
 
SLAB
,
    "wall" : "@@read_wall",
	]) );
	set("exits", ([
 
	"up" : MAGE"mage_guild",
	"down" : MAGE"storage",
 
	]) );
 
	set("pre_exit_func", ([
	"down" : "to_go_down",
	]) );
 
//	set("objects", ([
//	"worker" : MAGE"npc/worker",
//	]);
}
 
void init()
{
	add_action("write_wall","write");
//	if ((string)this_player()->query("name") == "karrimor") {
//		add_action("settitle","title");
//	}
}
/*
int settitle(string str)
{
	if (!str) return notify_fail("Syntax: title <title to set>\n");
this_player()->set("title",str+" "+(string)this_player()->query("c_name"));
	return 1;
}
*/ 
int write_wall(string str)
{
	if (!str) return notify_fail("��Ҫд���ﰡ?\n");
	if (str != "wall") return notify_fail("��Ҫ�һ��... \n");
    write("��ʼ��������....\n");
	this_player()->edit(TMP_FILE, "process", this_object());
	return 1;
}
 
int process()
{
	string text, title;
    seteuid(getuid());
    text = read_file(TMP_FILE);
    rm(TMP_FILE);
    title = (string)this_player()->query("c_name")+" � "+
        "/adm/daemons/weather_d"->query_c_game_time()+" д��:\n";
    write_file(WALL_FILE, title+text+"\n");
    write("Ok.\n");
	return 1;
}
 
string read_wall()
{
	this_player()->more(WALL_FILE);
	return "\n";
}
 
int to_go_down()
{
	if (wizardp(this_player()) || (this_player()->query_level() >= 
10) ) 
		return 0;
	tell_object( this_player(), "һ��ħ��������ס�����ȥ·\n");
	return 1;
}

