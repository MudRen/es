#include <mercury.h>
inherit ROOM;

void create()
{
   ::create();
   set_short( "ǧ��¥һ¥" );
   set_long(@ANGEL
��������ǧ��¥һ¥�����ڲ���װ�궼�����Ҿ�����Ƶģ�������֧��
�����������������ĵƾߣ��������ϵȵĽ��ļ��Ϲ�����ȫ��ȫ��ĵ�����
�Ƴɵģ��ذ������ø߼���ľ�����ɵģ��������������ʯͷ·��������һ
���ĸ��ܣ������л�Ʈ��һ�ɺ�̴ľ��������
ANGEL

   
         );
	set( "light",1);		
        set( "exits", ([
    "west"  :MR"inn06",    
    "up" :MR"inn2-1",
                ]) );
                            
         reset();                     
#include <replace_room.h>
}

