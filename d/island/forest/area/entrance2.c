#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("Beach","�ӱ�");
    set_long(@LONG
չ������ǰ����һƬ���ʵ�ɽ�ڣ�ƽʱ��Զ�����ܿ��ü����Ա߻���һ
���峺��С�������������Ϊ����ϡ�ٵĹ�ϵ������С�ӻ�����ά��ԭ����
��ò���Ա߻��п�ï�ܵĴ���(tree)����������Ӧ���Ѿ����������˰ɣ�
LONG
             );
    set("item_desc",(["tree":@C_LONG
��ô�����֦�����ķ���չ��ĩ�˻���������Ľ����������ÿ�����ï��
ѽ�����⼸��������͸����ֻС��ͣ��֦���ϳ��裬ͻȻ�����ϵ�Ҷ����
�����������ڵ��ϣ�������ร��ѵ����ں�С���ǶԻ���
C_LONG
           ]) );
    set("exits",([
            "west":AREA"upriver2",
            "north":AREA"entrance"]) );
    set_outside("island");
    set("objects",([
        "crab#2":"/d/noden/bluesand/monster/crab",
        "crab#1":"/d/noden/bluesand/monster/crab"]) );  
     reset();
}

void init()
{
    add_action("ask_passwd","pray");
}

int ask_passwd(string arg)
{
    if( !arg || arg != "password")
    return notify_fail(
    "���ϵ�С���Ƕ���˵������Ҫ��ͨ������(password)��\n");
    write(@ALONG
          
          ͻȻ����������Ҷ�������â���������ǰ�ۼ���һ�Ź���
        
        �����𽥻��������ͣ���һ�ж�̫ͻȻ�ˣ��㿴�������˶���ס�� 
        
        ��һ����������ػ��顡���롡վ������ǰ���Ͱ��Ķ���΢Ц��
        
     ���� �����˵������ܼ򵥵ģ�ֻҪ˵**��ͷެ��**�����ˣ����ߣ�ȥ�ɣ���
        
        �����ģ�����һ��һ���ļ����ˣ����� �������ɢȥ����ʧ�ˣ�

ALONG
                );
    this_player()->set_explore("island#2");
    return 1;
}
