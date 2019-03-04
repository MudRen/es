#include <irc.h>
#define BOARD "/d/std/IRC/irc_board"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Lobby","����" );
    set_long(
@C_LONG
����һ�����򵥵ķ��δ���. ��������ϯ�ض���, �����Ŷӵȴ�
����ES�����ǽ����һ��������(board), ��������һ�Ÿ�ʾ��
C_LONG
    );
    set("c_item_desc", ([
    	"board" : @C_BOARD
    	
    	���Ÿ�ʾ����д��:
	
    	��ʵ���ҽ�춽�������ʮ����������춽��󹤳����ݾٰ�����·�������
    	�����ֻ�, ��ӭӻԾ�μӡ�ͬʱ��������������, ֻҪ�й���·��������
    	���¾���ӭͶ�塣�����������н�ͨ��ѧ�ʿ����ǻ���Զ���ѧʵ���һ�
    	email �� workshop@cindy.cis.nctu.edu.tw������������� BBS Mud �档
    	         
	P.S. ES ���ٽ����ؼ�����������: Ĭ��IRIS��˧1000��, �ĳ�����

C_BOARD
]) );                                    
}
 
void init()
{
	add_action("do_kill","kill");
	add_action("do_auction","auction");
	add_action("do_drop","drop");
//      banish mage commands
	add_action("do_cast", "cast");
        add_action("do_meditate", "meditate");
//      banish thief commands
	add_action("do_backstab", "backstab");
	add_action("do_steal", "steal");
//      banish monk commands	
        add_action("do_exercise", "exercise");
        add_action("do_songin", "songin");
        add_action("do_eungon", "eungon");
//      banish scholar commands
	add_action("do_brood","brood");
        add_action("do_chutan","chutan"); 
        add_action("do_embattle","embattle");
        add_action("do_demand","demand");       
//      banish healer commands
	add_action("do_clot","clot");
	add_action("do_aid","aid");
	add_action("do_acupunct","acupunct");
//      banish adventurer commands
	add_action("do_hang","hang");
}

int do_drop()
{
	write("�����׼�Ҷ�������\n");
	return 1;
}



int do_acupunct()
{
	write("�����׼��ġ�\n");
	return 1;
}

int do_hang()
{
	write("�����׼��ɱ��\n");
	return 1;
}



int do_aid()
{
	write("�����׼���ȡ�\n");
	return 1;
}

int do_clot()
{
	write("�����׼ֹѪ��\n");
	return 1;
}

int do_demand()
{
	write("�����׼�ٻ���\n");
	return 1;
}


int do_embattle()
{
	write("�����׼����\n");
	return 1;
}


int do_chutan()
{
	write("�����׼�۵���\n");
	return 1;
}


int do_brood()
{
	write("�����׼������\n");
	return 1;
}


int do_eungon()
{
	write("�����׼�˹���\n");
	return 1;
}


int do_songin()
{
	write("�����׼�о���\n");
	return 1;
}


int do_exercise()
{
	write("�����׼������\n");
	return 1;
}

int do_meditate()
{
	write("�����׼ڤ˼��\n");
	return 1;
}

int do_steal()
{
	write("�����׼͵�ԡ�\n");
	return 1;
}


int do_backstab()
{
	write("�����׼���̡�\n");
	return 1;
}

int do_cast()
{
	write("�����׼ʩ����\n");
	return 1;
}

int do_auction()
{
	write("�����׼���ס�\n");
	return 1;
}

int do_kill()
{
	write("�����׼е����\n");
	return 1;
}	
	