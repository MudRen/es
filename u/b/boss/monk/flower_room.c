#include "saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
	::create();
    set_short("�����黨ָ��\ϰ����");
	set_long( @LONG_DESCRIPTION
�����黨΢Ц���Դ�Ϊ������ָ����������������ƽ�ʹȱ����Ƶж���ɱ�ˡ�   
����һ��Ƚ�С������ů�ķ��䣬������������һ��������͵�ζ������������һ
λ���ֵĺ��У���������Ц������һ�����շ�ľǽ������\���С���������ƺ���  
��ĳ�ְ����̴��ĺۼ����ѵ�����Ǿ��ŵ��黨ָ��?   ������λ����\ʦ�����ǰ
������ȿ���һ�ߵİ�ֽ(paper) ���Ϸ��ɻ�ȥ��ʮ����������    
LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper":@BOOK
                         
                           �黨ָ��ϰ�ʸ�

       1. ����ʮ������ɮ����֮�ʸ�
       2. �ĵ�ƽ�ͣ������¶����ߡ�      
       3. ����������ﵽ20��      
         
       �ﵽ�����ʸ��ߣ����ڴ�ϰ���黨ָ(practice keep-flower)֮���־��� 

       ע: ������������ľ�����������ɢ��\ (sangon keep-flower)��
           ��ı�����������Իᱻ������ֻ�ǲ����á�  
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : SAULIN"72" ]) );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"kon-fan" ]) );
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
	if( !arg || arg != "keep-flower" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/keep-flower") ) )
	     { write(" ���������ѧ����ָ! \n");
               return 1;
             }
        else {
        write("�����ָ����ʱ��ʧ��!!! \n"); 
        write("��������ʱ�ɾ���ֵ��Ȼ���� \n\n"); 
 		me->delete("monk_gonfu/keep-flower");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 
int to_study(string arg)
{
	object me;

	if( !arg || arg != "keep-flower") return 0;
	me = this_player();
	if( !wizardp(me) && (string)me->query("class") != "monk" )
		write("�㲻�Ǳ�����������Բ���ѧ�˹�\��\n");
    else if( (int)me->query_level() < 15 )
		write("���շ�Ц��: ���ְ��̫�ͣ�������ѧ�黨ָ��\n\n");
    else if( (int)me->query_perm_stat("str") < 20 )
		write("���շ�Ц��: ������������в��㡻\n\n");
	else if( !undefinedp(me->query("monk_gonfu/keep-flower")) ) {
		if((int)me->query("monk_gonfu/keep-flower")==35) {
			write("�շ�Ц��: ���Ѿ���ȫ�˽��黨ָ�İ����ˣ�������ȥ��ϰ��һ�־�����\n\n");
			me->set("monk_learn/72",0); }	
		else write(" �շ�Ц��:\n"
			"�����Ѿ�ѧ���黨ָ�ˣ����Ѳ��ܶ����ʲ�ᣬ��ȥ����ϰ��!��\n\n" ); }
	else if( me->query("monk_learn/72") )
		write("�շ�ҡһҡͷЦ��˵\n"
			"�����Ѿ�ѧ��һ�������!��ѧ�ھ����ڶడ!��\n\n" );
	else {
		write(@LONG

  ����! �������ھͽ����黨ָ�Ŀھ�����ʽ�ɡ��շ�����ĵ��ͷ��...

      �����ȱ����ڹ�\֮Ҫ��... 
      
     ����Դ��ģ�Ωȡ�������ɾ����̣����Ϸ���... ��  
     
     ������֮�����գ���Ե֮����������֮��...��  
     
     ���Լ�����������������ž�˼Ω���������ǣ������黨ָ�ڹ�\֮ҪҲ����

     ������Ҫ... ������˷�������...��         
     
     ���������ϣ��������ϣ���ָ��磬����ͳ֮...�� 
     
     �����������������飬ʵ������������ʵ...�� 
      ........................................... 
      
      �շ���ʦ����ʳ�ж�ָ�����ס�����黨֮״���º͵�����˵���书\ϸ��... 
      .................................. 
      
      �����ѧ������ָ��...����һƬ������� 
      
LONG
		);  
        me->set("monk_gonfu/keep-flower", 0);
        me->set("monk_learn/72",1);
	}  
	return 1;  
}

int clean_up() { return 1 ;}
