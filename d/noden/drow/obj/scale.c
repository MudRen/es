#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("scale","八歧蛇鳞");
    set_short("八歧蛇鳞");
    set_long(
@C_LONG
这是枚八歧大蛇脱落的蛇鳞，黯淡的黝黑色不能反射任何光线，
它的边缘极端的锐利，似乎能割裂任何东西，而它的形状很特殊
，似乎能放(put)在某处。
C_LONG
            );
    set("unit","枚");
    set("weight",15);
    set("value", ({ 10, "silver" }));
    set ("no_sale", 1);
}
