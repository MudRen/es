#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("dragon-claw room","���ִ������ָϰ����");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
����һ���ܿ������ķ��䣬������������һ��̴��ζ����춳��ò��ϵ�ʹ�ã��㷢
�ֵ��ϵ�ʯ�嶼��ĥ�ɺ�ɫ���ˡ�    
��������Ȼû�����ڣ�ֻ��ǽ������һ��ֽ(paper) ��  
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper":@BOOK
                         
                           �������ָ��ϰ�ʸ�

       1. ����ʮ������ɮ����֮�ʸ�
       2. ��������18��  
       3. �����ڹ�\��������72�� 

       ����֮���޴�ʦ���²鰸������ղſɻشˡ�                       
       �ﵽ�����ʸ��ߣ��������ڴ�ϰ���������ָ(practice power-finger) 

       ע: ������������ľ���������ɢ��\ (sangon power-finger)��
           ��ı�����������Իᱻ������ֻ�ǲ����á�  
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"down" : SAULIN"72" ]) );
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
	if( !arg || arg != "power-finger" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/power-finger") ) )
	     { write(" ���������ѧ���������ָ! \n");
               return 1;
             }
        else {
        write("��Ľ��ָ����ʱ��ʧ��!!! \n"); 
 		me->delete("monk_gonfu/power-finger");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 

int to_study(string arg)
{
	object me;

	if( !arg || arg != "power-finger" ) return 0;

	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("�㲻�Ǳ�����������Բ���ѧ�˹�\��\n");
	else if( (int)me->query_level() < 15 )
		write("�� ���ְ��̫�ͣ�û�ʸ�ѧ��\n");
	else if( (int)me->query_perm_skill("inner-force") < 72 )
		write("�� ��Ļ����ڹ�\(inner-force)����̫�û�ʸ�ѧ��\n");
	else if( ((int)me->query_perm_stat("str") < 17) 
			  )
		write(" ���������������û�ʸ�ѧ�������ָ��\n");
	else if( !undefinedp(me->query("monk_gonfu/power-finger")) )
		write("���Ѿ�ѧ��������ָ�ˣ���ȥ��ϰ��!\n");
    else if( me->query("monk_learn/72") )
		write("���Ѿ�ѧ��һ�������!\n");
    else {
		write(@LONG
	
     �㷭�� �������ָ ���ţ���ʼϸϸ��������... 

     �����ȱ����ڹ�\֮Ҫ��... 

     ��һ����Ϊ�������λ���Ӱ����������磬Ӧ�����ǹ�... ��ղ������ľ� ��  
     
     ���ܸ�֮�����գ���Ե֮�����...��
 
     ���⵫Ѱ��������ס������;��ã��һ����Ȼ�����˴������ָ�ڹ�\֮ҪҲ����

     ���������ϣ��������ϣ���ָ��磬����ͳ֮...�� 
     
     �����������������飬ʵ������������ʵ...�� 
      ...........................................
      
     �������ħ�����˱�ָ��֮��ʽ... ���̶�����......��...
      ..................................
      
      �����ѧ���� �������ָ...
 
LONG
 		);  
 		me->set("monk_gonfu/power-finger", 0);
 		me->set("monk_learn/72",1);
 	}  
    return 1;  
} 
