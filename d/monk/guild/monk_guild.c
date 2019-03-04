
#include "saulin_temple.h" 
#define  BOARD "/d/monk/guild/monk_board"

inherit GUILD;

void create()
{
        object guild_master;
	::create();
	set_short("�޺���");
	set_long( @LONG_DESCRIPTION
һ̤���޺�������۹����ϱ����Թ����ʮ���޺������㡣��������������Ҷ������
������  ʮ�����޺�����֮��̬���Ƹ�����ͬ�����Ƿ���������ǽ�ߣ�ǽ��ıڻ�����ÿ
���޺��õ��ɷ�Ĺ��̡�
�����޺���������������ɮ�ǻ����д���ѧ�ĵط�������ɮ��Ŀǰ���ڴ˴������������
�����似��ȭ���������⽣Ӱ��ʮ�����֡�����������������ɮ�����У������������ 
�õ���ص���Ѷ���㷢���޺��ý����ǽ��(wall)�����ý��ָ������һЩ�֡�  
�����ϡ��������������ڣ��ֱ�ͨ����������������������Իص����á�
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
          	"wall" : @LONG_TEXT
����������������������������������������������������������������
�޺�������������ɮ��ѧϰ����֮����Ҳ���˳��������ֺ��й��ᡣ
����������  һ����Ե����������Ѫ����Ѫ����û���ֵ���ħ�⣬�� 
�Ƕ���ӭ�������룬�����ְ����¹���������ز��д�Ů�ͣ�������
������Ů�ӣ���ˡ�����޷��������(join)��

help guild ���Եõ���һ���Ĺ���ָ��˵����
help monks ���Ե�֪���ֺ��й�����������Ƽ�˵����

�����𱾹��Ὺ��PK
����������������������������������������������������������������
LONG_TEXT
 ]) );
	set( "exits", ([ 
	        "south": SAULIN"gonfu_room4",
 	        "east" : SAULIN"gonfu_room1",
 	        "west" : SAULIN"monk_pass",
                "north": SAULIN"gonfu_room3" ]) );
	set( "no_monster", 1 );
        guild_master=new("/d/monk/guild/monsters/shan-chi" );
        guild_master->move(this_object());
	                 BOARD->frog();
	set_guild( "monk" );
        set( "pre_exit_func", ([    "north" : "check_monk",
                                    "south" : "check_monk",
                                    "east"  : "check_monk" 
	])  ); 
reset();
}

int check_monk()
{   
        if( wizardp( this_player() ) ) return 0; 

 if( (string)this_player()->query("class")!="monk" && present("shan chi") ) {
//if( (string)this_player()->query("class")!="monk"  ) {
		write( can_read_chinese()?
                "����˫�ֺ�ʮ��Ҿ����Ի������λʩ���Բ������ֽ���ֻ��������ɮ���ܽ�ȥ����\n":
			"Sorry, that is for monk only.\n" );
		return 1;
	}
	
  if( (int)this_player()->query("alignment")<-200 && present("shan chi") ) {
		write( can_read_chinese()?
"����ŭĿ���ӵ�Ի������Ϊ������ɮ����Ϊ���������������ѧ����!!!��\n":
			"Get out of here!!!\n" );
		return 1;
	}
	return 0;

}