#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "ǧ��¥��¥" );
   set_long(@ANGEL
��������ǧ��¥��¥������Ĺ����һ¥������������ͬ��ֻ��ͨ����խ��
��࣬��˵����Ϊ��ֹ���˴������ֶ���Ƶģ��ذ�ĳ��ý��׷���������ľ��
���ɣ�ֻҪ����һ�����¥���䷢��������һ���ᱻ�ڶ�¥��������ʿ��������
�����л�Ʈ��һ�ɺ�̴ľ��������
ANGEL

   
         );
	set( "light",1);
	set("objects",([
	"zark":MOB"zark"
	]));		
        set( "exits", ([
    "up"  :MR"inn3-1",    
    "south" :MR"inn2-5",
                ]) );
        set("pre_exit_func",([
        "up":"to_up"
        ]));                            
         reset();                     
}
int to_up()
{
 if(!present("zark")){
 return 0;
 }
else{
 write(@AAA
 ����վ������ǰ��ס�㣬��˵����С�ӣ��㲻���ҵ���ѽ!�����������ȥ!
AAA
 );
 return 1;
 }
 }
 
