#include <mercury.h>
inherit DOORS;
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
    "east"  :MR"inn06",    
    "south" :MR"inn03",
    "north" :MR"inn05"
                ]) );
      create_door("south","north",([
                  "keyword" : ({"door","ebony door"}),
                  "status"  : "closed",
                  "name"    : "Ebony Door",
                  "c_name"  : "��̴ľ��",
                  "c_desc"  : "һ���ú�̴ľ���ţ������þ�ϸ���ֹ�\n"
                              "���һ����������\n"
                  ]) );
                            
         reset();                     
}

