//sage�޸��ڣ� 98-6-11
#include "/d/monk/guild/saulin_temple.h" 

inherit ROOM;
inherit DAEMON;

void create()
{
        ::create();
    set_short("ɱ���书��ϰ��");
        set_long( @LONG_DESCRIPTION
����һ���ܳ�ʪ�����ķ��䣬������������һ��Ѫ����ζ����춳�û�����������㷢
�ֵ��ϵ�ʯ�嶼�����˺���һ����̦��    
����������������һ�ߺ��ǣ���֪���Ǻ����⣬ǽ������һ��ֽ(paper) ��  
LONG_DESCRIPTION
        );
    set("c_item_desc",([
         "bone":@BOOK
          һ�ߺܳ¾ɵĺ��ǣ�������ĳ�����ָ���������������������Ψһ�ļ���
      Ʒ���뵽�������ĵ��²�����һ�־���֮�飬Ҫ�����±��˿�����������
      ����ȥ������λ��ǰ���ļ���ͷ��        
BOOK
         "paper":@BOOK
                         
                           ͵����������ϰ�ʸ�

       1. �Ǳ����Ụ��������ݡ�
       2. Ҫ�ǳ�а��  
       3. .............(���ɸ��˵������������Ƿ���Ե)�� 

       �ﵽ�����ʸ��ߣ������ڴ���ϰ͵��������(practice getsb-sword) 

       ע: ����������ڶ࣬��������һ�������ھ����ڶ��ԭ��ÿ����Աֻ����
           ��һѧ֮��
BOOK
]));         
        set( "light", 1 );
        set( "exits", ([ 
//             "down" : SAULIN"72" ]) );  
               "west" : "/d/killer/guild/killer_guild"]) );
        reset();
}

void init()
{
        add_action("to_study","ketou");
//      add_action("to_delete","sangon");
}

/*
int to_delete(string arg)
{
        object me;
        if( !arg || arg != "bone" ) return 0;
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
*/      /*��ʱ��������ɢ��*/

int to_study(string arg)
{
        object me;

        if( !arg || arg != "getsb-sword" ) return 0;

        me = this_player();
        if( !wizardp(me) && (string)me->query("class") != "killer" )
                write("�㲻�Ǳ�����������Բ���ѧ�˹�\��\n");
//        else if( (int)me->query_level() < 15 )
//                write("�� ���ְ��̫�ͣ�û�ʸ�ѧ��\n");
//        else if( (int)me->query_perm_skill("inner-force") < 72 )
//                write("�� ��Ļ����ڹ�\(inner-force)����̫�û�ʸ�ѧ��\n");
//        else if( ((int)me->query_perm_stat("str") < 17) 
//                          )
//                write(" ���������������û�ʸ�ѧ�������ָ��\n");
//        else if( !undefinedp(me->query("monk_gonfu/power-finger")) ) {
//                if((int)me->query("monk_gonfu/power-finger")==35) {
//                        write("���Ѿ���ȫ�˽�������ָ��Ҫ���ˣ�������ȥ��ϰ��һ�־�����\n\n");
//                        me->set("monk_learn/72",0); }   
//                else write("���Ѿ�ѧ��������ָ�ˣ���ȥ��ϰ��!\n"); }
          else if( me->query("killer_learn/72") )
                  write("���Ѿ�ѧ��һ�������!\n");
          else {
                write(@LONG
        
       ͻȻ������վ������������һ����Ц��������ë���Ȼ���ŵ�˫��һ��
   �����ڵأ����������ֻ��ץ�����Դ�ץ������ֻ�����Դ�һ���ʹ������
   �������������ѡ����ͻ��˹�ȥ��

LONG
                );  
                me->set("monk_gonfu/power-finger", 0);
                me->set("monk_learn/72",1);
        }  
    return 1;  
} 

int clean_up() 
     { return 1; }
