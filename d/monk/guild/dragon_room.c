
#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("������צ��ϰ����");
	set_long( @LONG_DESCRIPTION
����һ�������Ĵ󷿼䣬ǽ�����ɷ����д��һ���������֣��㷢��ǽ�ں���������
��\�౻ǿ��ָ�������ĺۼ���
��������һ���ߴ��ɮ�ˣ����Ϸ��������ƾɵ����ţ���ɮ�ƺ���ȫû��ע�⵽��Ĵ���
 ����Ȼ�ڱ�Ŀ�����˹�\���㷢��ǽ������һ�ŷ��Ƶ�ֽƬ(paper)�������ƺ�д��һЩ��
����ɮ���������ű߷���һ���飬����Լ�����и����֡����߻ص���ʮ���������� 
LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper":@BOOK
                         
                           ��צ����ϰ�ʸ�

       1. ����ʮ������ɮ����֮�ʸ�
       2. ���ݳ���16����������16��  
       3. �����ڹ�\��������72�� 
                       
       �ﵽ�����ʸ��ߣ����ڴ�ϰ����צ��(practice dragon-claw)֮���־��� 

       ע: ������������ľ�����������ɢ��\ (sangon dragon-claw)��
           ��ı�����������Իᱻ������ֻ�ǲ����á�  
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"west" : SAULIN"72" ]) );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"kon-shin" ]) );
	reset();
}

void init()
{
	add_action("to_study","practice");
	add_action("to_delete","sangon");
}

int to_delete(string arg)
{
	object me;
	if( !arg || arg != "dragon-claw" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/dragon-claw") ) )
	     { write(" ���������ѧ����צ��! \n");
               return 1;
             }
        else {
        write("�����צ�ֹ�\����ʱ��ʧ��!!! \n"); 
        write("��������ʱ�ɾ���ֵ��Ȼ���� \n\n"); 
 		me->delete("monk_gonfu/dragon-claw");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 
int to_study(string arg)
{
	object me;

	if( !arg || arg!="dragon-claw") return 0;

	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("�㲻�Ǳ�����������Բ���ѧ�˹�\��\n");
    else if( (int)me->query_level() < 15 )
		write("������˵: ��ĵȼ�̫�ͣ�û�ʸ�ѧ��צ�֡�\n\n");
    else if( (int)me->query_perm_skill("inner-force") < 72 )
		write("������˵: ��Ļ����ڹ�\(inner-force)����̫�û�ʸ�ѧ��צ�֡�\n\n");
    else if( ((int)me->query_perm_stat("str") < 16) ||
    		 ((int)me->query_perm_stat("dex") < 16) )
		write("������˵: ������������ݲ�����û�ʸ�ѧ��צ�֡�\n\n");
	else if( !undefinedp(me->query("monk_gonfu/dragon-claw")) ) {
		if((int)me->query("monk_gonfu/dragon-claw")==35) {
			write("����˵��: �ţ���ѧ�Ļ������ðɣ�������ȥ�����־�����\n\n");
			me->set("monk_learn/72",0); }	
		else write(" ���Դ������Ͽ����㣬����һ��:\n"
			"������׳հ�! ���Ѿ�ѧ����צ���ˣ�Ҫר���Ϳ�ȥ��ϰ��!��\n\n" ); }
	else if( me->query("monk_learn/72") )
		write(" ���Դ������Ͽ����㣬����һ��:\n"
			"������̰�İ�! ���Ѿ�ѧ��һ������ˣ���ȥ��ϰ��!��\n\n" );
	else { 
		write( @LONG

  ����! �������ھͽ�����צ�ֵĿھ�����ʽ�ɡ�����վ����Ц��...
 
     ������Ҫ... ������˷�������...��
              
     ���㷨... ���䷭���������˲�.....��
     
     ���������ϣ��������ϣ���צ��磬����ͳ֮...�� 
      ........................................... 
 
     �����������������飬ʵ������������ʵ...�� 
      ........................................... 
      
     �����������·��ϡ������������»�Ȧ̽��... 
     
     ������׽Ӱ����硻....                
      .................................. 
      
      �����ѧ������ʮ��ʽ��צ����...
      
LONG
		);  
        me->set("monk_gonfu/dragon-claw", 0);
        me->set("monk_learn/72",1);
	}
	return 1;  
} 

int clean_up() { return 1 ;}
