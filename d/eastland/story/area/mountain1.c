#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("ɽ��");
	set_long( @LONG
����ɽ��������Զ���ǲ��͵��壬����һĻĻ���̲���ס��������죬�ϱ���
��һ���£���ãã��һƬ����ס�ͷ�ϵİ����붥ֻ��������߶ȣ�һĨĨ����
��ɫ�ı��ӣ���Ҫѹ������������һ������Զ�������̲�������������°��ǵ��
���������ӣ����ɽ֮���ν���һ��Ϫ�����������ȣ���ˢˢ����������֪�߶���
�Σ�������һ�ζ����ˡ�������������᫵�ɽ·�����ߵ������ǿ�ɽ�ڣ�������
·���п�ʯ��(stone)����
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	      "east" : SAREA"mountain2",
        ]) );
	set("c_item_desc",([
	  "stone":@LONG
ʯ����д����
���������������˾����밮ϧ�Լ�����������Ҫ���������µ�Ϫ������ȥ( jump down ) 
           �����ⷢ��Σ�ա�����
LONG	  
	]) );
	reset();
}
void init()
{
   add_action("do_jump","jump");
}	
int do_jump(string arg)
{
    if ( !arg || arg!="down" ) return 0;
    write(@LONG
    
�������ߵ�Ϫ��һ�����������������ɣ�ӭ��ķ�ѹ���㴭����
�����������޷����κζ�������

LONG
    );
    this_player()->set_temp("block_command",1);
    call_out("back",5,this_player());
    return 1;
}
void back(object player)
{
    write(@LONG

�ۿ����Ҫˤ�ķ�����ǣ���Ȼ����������һ���ε�����������
����ȥʹ�㰲ȫ�������˿�����𣡣�

LONG
    );    
    player->delete_temp("block_command");
    player->move_player(SAREA"bottom2",({
        "%s�����ߵ�Ϫ��һ����\n",
        "%s�Ӹ߿�������������\n"}),"");
    return ;
}
