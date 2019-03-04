
#include "saulin_temple.h" 

inherit ROOM;

void create()
{
	::create();
    set_short("�����ڹ�\�ķ���");
	set_long( @LONG_DESCRIPTION
�����ڵ����޺��õ��ڹ�\�ķ��������ס�ڹ�\����ѧ֮�ף��ڹ�\��һ�ж���̸��
���ֵĳ����ڹ�\�ǡ����ֻ����ķ�������ο��������ֽ�ϵ�˵��(broken_paper)��   
���ֵĴμ��ڹ�\�ǡ������޺��ķ���������Ҫ�С�������ɮ�����ϵ�ʵ��������ѧ��
�������һ������������(broken_book)����¼�������޺��ķ����㲻��ȥ����������  
���»ص����䷿�����������ֳ����ķ���������ͨ��������ʮ����������\����
LONG_DESCRIPTION
	);

    set("c_item_desc",([
         "broken_paper":@PAPER
ǽ��ݲݵ�д�˼�����...
�����ֻ����ķ���  
�������(study basic) ѧ�����ڹ�\�ķ���
ע��û�Ҫ���û����������ɲŻ�������  
PAPER
         ,"broken_book":@BOOK
��Ƥ��д���������޺��ķ���  
ֻҪ��С����ܵ����� ��͸��������������(god help) �㽫��ѧ�����ڹ�\�ķ���
ע�������ֵ��С�� [��ϰ�ķ�] �� [�����ڹ�\] �й� 
BOOK
]));         
	set( "light", 1 );
	set( "exits", ([ 
		"north" : SAULIN"inner_room1",
		"down" : SAULIN"gonfu_room3",
		"up" : SAULIN"72" ]) );
	reset();
}

void init()
{
 add_action("to_study","god");
 add_action("basic","study");
}



int basic(string arg)
{
  string class1;

  class1=(string)this_player()->query("class");
  if ( !arg || arg!="basic") return 0;
  else if ( class1 !="monk"){
     write("��Ǹ�㲻�Ǳ�������������㲻��ѧ���ķ�\n");
     return 1;
                           }
 
        else if ((int)this_player()->query("force_effect")>=1){
write(
" һ����һ������\�ĺ��п����㣬������Ц�� \n 
�����ǰ׳հ�! ���Ѿ�ѧ�������ķ�����õ��ķ�����!!! ����!��\n\n" );
          return 1;
                                                              }       
        else {
write(
"\n\n �㿴�����з���һ����â��ҫ���� \n");

call_out("idle_teme",10); 
write("һ������͵�����˵��...... \n

        ��ӭ�������ֺ���ն����ħ������
        �����ķ�ֻ�Ǻܻ������ķ���ϣ���������������� \n\n"); 
        this_player()->set("force_effect",1);
        return 1;  
             } 

}

int to_study(string arg)
{
  string class1;
  int level;

  level=(int)this_player()->query_level(); 
  class1=(string)this_player()->query("class");
  if ( !arg || arg!="help") return 0;
  else if ( class1 !="monk"){
     write("��Ǹ�㲻�Ǳ�������������㲻��ѧ���ķ�\n");
     return 1;
                           }
    else if (level<4){
    write("������˵: С�ϵܰ�!!! ����˵���г�����ɮ���ϵ�ʵ�����ܽ����ķ���!��\n\n");
         return 1;
                     } 
        else if ((int)this_player()->query("force_effect")>=2){
write(
" ������һ�죬�ֱ��㳳�Ĳ���˯��... ���ܲ�ˬ�Ŀ��������\n 
�����ǰ׳հ�! ���Ѿ�ѧ���ķ��˲�����ѧ��!!!��\n\n" );
return 1;
                                                              }       
        else {

call_out( "idle_time",5);
write(
"\n\nͻȻ����һ�����...... \n");
call_out("idle_time",10);
write(" 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    
@@@ �����޺�����է�֣���������������޺��ķ��İ��� @@@ 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n" );
        this_player()->set("force_effect",2);
        return 1;  
             } 
}

 
void idle_time()
{
write(" \n");
}
 


