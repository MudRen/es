#include "../island.h"
#include <money.h>

inherit SHOP;

void create()
{
    ::create();
    set_short("�¼ǹ�����");
    set_long(@LONG
�������ɵ���Ψһ�Ĺ����У�ǽ�Ϲҵĺ���д������Сͨ�ԡ��ĸ���
�֣�����װ��ǽ�����ʮ��Ĳ���һ�����ݷ�������м�ֵ�Ĺ������
���������Ƶġ�������ϰ��и��Ⱥã�ϲ���ռ�һЩ�������ܵ����ߣ���
���۵ı��������Լ���أ�Ϊ�����и���Ļ����ʶ���������ߣ��㿪��
��ҹ������������˿͡��ڹ�̨�Ϸ�����һ������(words)��
LONG
            );
    set("light",1);
    set("item_desc",(["words":@LONG
    
                 �� �� �� �� �� ��
             ��                     �� 
             ��                     ��
             ��                     ��
             ��                     ��
             ��                     ��
             ��                     ��
             ��                     ��
             ��                     ��
             ��                     ��
             ��                     ��
             ��                     �� 
             ��                     ��
LONG
          ])); 
    set("exits",(["north":ITOWN"town08"]) );
    storeroom()->set("objects",([
               "torch":"/obj/torch",
               "bag":"/obj/bag",
               "bandage":"/obj/bandage"
                ]) );
    set("objects",([
        "trashcan":"/obj/trashcan",
        "keeper":IMON"shopkeeper"
                ]) );
    reset();
    replace_program(SHOP);
}
