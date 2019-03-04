#include "saulin_temple.h" 

inherit ROOM;

void create()
{
	::create();
    set_short("Body defense room","���ֽ�ղ�������\ϰ����");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
һ���뷿�䣬���Ŀ�����ȱ�����һ�����������ݵ���ɮ���������������ò���
д�������ֽ�ղ�����\��������Է��ִ󲿷ݵľ������ǹ����õģ��������ղ�
������\���Ǵ�������õĹ�\��Ҫѧ��һ������ȫ�����ѡ���ˡ� 
ǽ������һ�ŵ�ֽ��(paper)�������ƺ�д��һЩ�֣����߿ɻ���ʮ����������
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "paper" : @BOOK
                         
                           ��ղ�������\��ϰ�ʸ�

       1. ����ʮ������ɮ����֮�ʸ�
       2. ���ݵ���18��  
       3. �����ºͣ���ϲ����ɱ���ߡ�       

       �ﵽ�����ʸ��ߣ����ڴ�ϰ����ղ�������\(practice body-def)

       ע: ������������ľ�����������ɢ��\ (sangon body-def)��
           ��ı�����������Իᱻ������ֻ�ǲ����á�  
BOOK
	]) );
	set("light", 1 );
	set("exits", ([ 
		"north" : SAULIN"72" ]) );
	set("objects", ([
		"Monk" : SAULIN_MONSTER"kon-gem" ]) );
	reset();
}

void init()
{
	add_action("to_study", "practice");
	add_action("to_delete","sangon");
}

int to_delete(string arg)
{
	object me;
	if( !arg || arg != "body-def" ) return 0;
	me = this_player();
	if( undefinedp( me->query("monk_gonfu/body-def") ) )
	     { write(" ���������ѧ����ղ�������\! \n");
               return 1;
             }
        else {
        write("��Ľ�ղ�������\��ʱ��ʧ��!!! \n"); 
        write("��������ʱ�ɾ���ֵ��Ȼ���� \n\n"); 
 		me->delete("monk_gonfu/body-def");
 		me->set("monk_learn/72",0);
                return 1;  
         }
} 
int to_study(string arg)
{
	object me;
	
	if( !arg || arg != "body-def" ) return 0;

	me = this_player();	
  	if( !wizardp(me) && (string)me->query("class") != "monk" )
  		write("�㲻�Ǳ�����������Բ���ѧ�˹�\��\��\n");
  	else if( (int)me->query_level() < 15 )
		write("�ռ�ҡͷ˵: ���λ��̫�ͣ���������ղ�������\��\n\n");
	else if( (int)me->query_perm_stat("dex") < 18 )
		write("�ռ�˵: ������ݲ�����û�취���㡣\n\n");
	else if( (int)me->query("alignment") < 1000 )
		write("�ռ���ʮ��: �����ӷ�... ʩ��ɱ��̫��, ����ϰ���书\!��\n\n" );
	else if( !undefinedp(me->query("monk_gonfu/body-def")) )
		write("�ռ�̾��һ����˵: ���Ѿ�ѧ����ղ�������\�ˣ�Ҫר���Ϳ�ȥ��ϰ!��\n\n" );
    else if( me->query("monk_learn/72") )
		write("�ռ�˫�ֺ�ʮ��: ���У����Ѿ�ѧ��һ������ˡ�\n\n" );
	else {
		write( @LONG

  ��! �������ھͽ����ղ�������\�Ŀھ���! �ռ�Ц��:
   
      ����Ҫ... ������˷�������...
      
      �㷨... ���䷭���������˲�....
      
      �������ϣ��������ϣ�������磬����ͳ֮...
      ...........................................
      
      ���������������飬ʵ������������ʵ....
      ...........................................
      
      �����̴�У�����춰ٻ㣬���������.....
      
      �ռ���ʦһ�����������������\��Ҫ��...                
      ..................................

      �����ѧ���˽�ղ�������\��...
      
LONG
		);
		me->set("monk_gonfu/body-def", 0);
		me->set("monk_learn/72", 1);
	}
	return 1;
} 
