#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
    set_short("����������\�ķ���");
        set_long( @LONG_DESCRIPTION
�����Ƕ��������о������ķ���,�����������Կ��ֶԻ�ǿ���ĵ��˺͹���
��ԭ���������ڹ�,�����о������ڿ���Ϊ��ʿѧϰ�������ڹ��ķ�,�Ը���
�ĶԿ����ˡ��ķ���������һ�£�wall�������ڹ��ķ����ܷ�ѧ����Ҫ����
�����컯�ˡ�
LONG_DESCRIPTION
        );

    set("c_item_desc",([
         "wall":@WALL
ǽ��ݲݵ�д�˼�����...
������ڹ������ķ���  
�������(study basic) ѧ�����ڹ�\�ķ���
ע��û�Ҫ���û����������ɲŻ�������  
WALL
         ,"wall":@BOOK
��Ƥ��д��������ڹ��ķ���  
ֻҪ��С����ܵ����� ��͸��������������(god help) �㽫��ѧ�����ڹ�\�ķ���
ע�������ֵ��С�� [��ϰ�ķ�] �� [�����ڹ�\] �й� 
BOOK
]));         
        set( "light", 1 );
        set( "exits", ([ 
                "north" : "/u/c/creative/workroom",
                 "up"     : "/u/b/boss/workroom"]));
                 reset();
}

void init()
{
 add_action("to_study","god");
 add_action("basic","study");
}



int basic(string arg)
{
  string class;

  class=(string)this_player()->query("class");
  if ( !arg || arg!="basic") return 0;
  else if ( class !="knight"){
     write("��Ǹ�㲻�Ǳ�������������㲻��ѧ���ķ�\n");
     return 1;
                           }
 
        else if ((int)this_player()->query("force_effect")>=1){
write(
" һ����һ������\����ʿ�����㣬������Ц�� \n 
�����ǰ׳հ�! ���Ѿ�ѧ�������ķ�����õ��ķ�����!!! ����!��\n\n" );
          return 1;
                                                              }       
        else {
write(
"\n\n �㿴�����з���һ����â��ҫ���� \n");

call_out("idle_teme",10); 
write("һ������͵�����˵��...... \n

        ��ӭ���뱣�����ҵ�����
        �����ķ�ֻ�Ǻܻ������ķ���ϣ���������������� \n\n"); 
        this_player()->set("force_effect",1);
        return 1;  
             } 

}

int to_study(string arg)
{
  string class;
  int level;

  level=(int)this_player()->query_level(); 
  class=(string)this_player()->query("class");
  if ( !arg || arg!="help") return 0;
  else if ( class !="knight"){
     write("��Ǹ�㲻�Ǳ�������������㲻��ѧ���ķ�\n");
     return 1;
                           }
    else if (level<18){
    write("������˵: �ֵܰ�!!! ֻ����ʿ�������ܽ����ڹ��ķ���!��\n\n");
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
@@@ �����������է�ִ�ȣ��������������ڹ��ķ��İ��� @@@ 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n" );
             this_player()->set("max_fp", "@@query_max_fp");
        this_player()->set("force_effect",2);
        return 1;  
             } 
}

 
void idle_time()
{
write(" \n");
}
 

