#include "takeda.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set_short("�ּ�С��");
       set_long( @Clong
��һ���޴����դ֮�ᣬ��һ����ɭɭ���ּ�С·��Ũ�ܵ�֦Ҷ�������
��ȫ���ڱ���������ʹ����������磬����Ҳ�����ֲ�����ָ��С���ĵײ���
������ʪ��������Ҷ���ݷ�������䵽����ʱ������Ҳû��Ǭ�������ɵĸ���
�����˺���ɫ����̦��һЩ��ţ���������У������������ķ���Һ����˵��ɽ
���ú���ǰ���������˴���ȡ�֣���������ƺ�������ʲ���£���Ҷ�������
���ˡ�
Clong
          );
set("exits",([
               "south":TROOM"gate3",
              ]) );
create_door("south","north",([
             "keyword" : ({"iron prism","prism" }),
             "status" : "closed",
             "c_desc" : "һ�����ص���դ",
             "c_name" : "��դ",
             "name":"iron prism",
             "desc":"an iron prism"
              ]) );
reset();
}
int clean_up() { return 0; }