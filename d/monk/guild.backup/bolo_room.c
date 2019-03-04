#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("dragon-claw room","���ְ�����ϰ����");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
����һ���ܿ������ķ��䣬������������һ��̴��ζ����춳��ò��ϵ�ʹ�ã��㷢
�ֵ��϶���һ�����Ľ�ӡ��    
��������������ʮ�����������ʹ�ú�ѧϰ���似����ϴ�ʦ����������������ʮ����
�Ļ���ˣ�����Է���������̡���Ȼǽ�ϵ���֪(paper) �㲻���ȿ�����  
C_LONG_DESCRIPTION
	);

    set("c_item_desc",([
         "paper":@BOOK
                         
                           ��������ϰ�ʸ�

       1. ����ʮ������ɮ����֮�ʸ�
       2. ���ݳ���16����������17��  
       3. �����ڹ�\��������70�� 
                       
       �ﵽ�����ʸ��ߣ����ڴ�ϰ��������(practice bolo-fist)֮���־��� 

       ע: ������������ľ�����������ɢ��\ (sangon bolo-fist)��
           ��ı�����������Իᱻ������ֻ�ǲ����á�  
BOOK
       ]));         
	set( "light", 1 );
	set( "exits", ([ 
		"east" : SAULIN"72" ]) );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"shi-hur" ]) );
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
	if( !arg || arg != "bolo-fist" ) return 0;
	me = this_player();
	if( undefinedp(me->query("monk_gonfu/bolo-fist")) )
        {	write("���ҡ��ҡͷ˵: ���������ѧ��������!\n");
                return 1;
        }
        else {
               write("�ð����Ҿͳ�ȫ��!!!! \n\n");
               write("��ϴ������㱳��һ�ģ���İ���������ʱ��ʧ��!!!\n\n");
               write("�����İ�! �´�������������ʱ��Ŀǰ�ľ���ֵ������ʧȥ!��\n\n");
 		me->delete("monk_gonfu/bolo-fist");
 		me->set("monk_learn/72",0);
                return 1;  
              }
} 

int to_study(string arg)
{
	object me;
	if( !arg || arg != "bolo-fist" ) return 0;
	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("�㲻�Ǳ�����������Բ���ѧ�˹�\��\n");
	else if( (int)me->query_level() < 15 )
		write("�����Ի: ���ְ��̫�ͣ�û�ʸ�ѧ�����ơ�\n");
	else if( (int)me->query_perm_skill("inner-force") < 70 )
		write("�����Ի: ��Ļ����ڹ�\(inner-force)����̫�û�ʸ�ѧ�����ơ�\n");
	else if( ((int)me->query_perm_stat("str") < 17) ||
			 ((int)me->query_perm_stat("dex") < 16) )
		write("���Ц��: ������������ݲ�������û�ʸ�ѧ�����ơ�\n");
	else if( !undefinedp(me->query("monk_gonfu/bolo-fist")) )
		write("���ҡ��ҡͷ˵: ���Ѿ�ѧ���������ˣ���ȥ����ϰ��!\n");
    else if( me->query("monk_learn/72") )
		write("���ҡһҡͷ˵: ���Ѿ�ѧ��һ�������!\n");
    else {
		write(@LONG
	
	����! �������ھͽ�������ƵĿھ�����ʽ�ɡ��������ĵ��ͷ��...

     �����ȱ����ڹ�\֮Ҫ��... 

     ��ȴ���׷�֮�ģ��Ծ��׷�֮������֮�޴�����׷�֮��δ�... ��  
     
     ������֮�Ǳ��գ���Ե֮���༰��...��
 
     ���ⲻѰ�����ڲ�ס������;��ã��һ����Ȼ�����˰������ڹ�\֮ҪҲ����

     ������Ҫ... ������˷�������...��         
     
     ���������ϣ��������ϣ�������磬����ͳ֮...�� 
     
     �����������������飬ʵ������������ʵ...�� 
      ...........................................
      
     �������޷� ��������΢��ʵ��������������...��...
      ..................................
      
      �����ѧ���˰����Ʒ�...
 
LONG
 		);  
 		me->set("monk_gonfu/bolo-fist", 0);
 		me->set("monk_learn/72",1);
 	}  
    return 1;  
} 
