
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("???","�㳡");
  set_long(@Long
Long
,@CLong
һ���ܴ�Ĺ㳡,���ϳ�����һЩ��ɫ��ֲ��.��̧ͷһ��,ֻ��һ���ܴ�ܴ�
�Ķ�ͨ�����. �ƺ��Ǹ������˹��ھ��,���㲻��ȷ�� .�ڹ㳡��������һ�ھ�
(well),һЩ�������ھ��Դ�ˮ.������һЩ��ֵ��������������Ͽ�,��һЩ��
��սʿ�������������.���ɹ�ȥ���������֪��Щ���������Ӧ�þ��Ǵ�˵�в�
����ֵ�ʨӥ(griffon).
CLong
);
set("exits",([
               "west":Deathland"/palace/pa_06",
             ]) );
set("c_item_desc",([
    "griffon":@Cgriffon
����һ�Գ��,������ʨ�ӵ�ͷ����������
Cgriffon
    ,"well" : "@@to_look_well",
    ]) );
set("objects",([
    "warrior":Monster"/warrior",    
    ]) );
    
::reset();
}

string to_look_well()
{
     write("���㿴����ھ�,��Ȼ��ĽŻ���һ��,������˾���.\n"
          );
     say(this_player()->query("c_name")+"�ھ�����ʧ��.\n");
     this_player()->move_player(Deathland"/palace/well01","SNEAK","");
     return "�⾮����Ȳ�����,��Ӧ���ܺ����׵�����ȥ\n";
}

