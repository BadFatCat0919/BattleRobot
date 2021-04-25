///////////////////////////////////////////////////////////////////-=505-Tech=-///
//无线调试菜单板-菜单
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//编写：徐天泽
//中国民航大学电子科技创新创业实践基地505创客实验室
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//本程序仅供学习参考，未经许可，不得用于其它任何用途
///////////////////////////////////////////////////////////////////-=505-Tech=-///
#include "menu.h"
///////////////////////////////////////////////////////////////////-=505-Tech=-///
//注意！所有新建的页面都需要在这里添加:
MENU_PAGE Homepage,Author;
/********************************************************************************
  页面名：	主页
  父页面：	空
*********************************************************************************/
__M_PAGE(Homepage,"BOARD SETTINGS",PAGE_NULL,
{
	SOLGUI_Cursor(6,0,4);
	
  SOLGUI_Widget_GotoPage(0,&Author);
	SOLGUI_Widget_OptionText(1,BLUETOOTH?"BLUETOOTH:   OK":"BLUETOOTH:ERROR",BLUETOOTH);
});
/********************************************************************************
  页面名：	作者信息
  父页面：	主页
*********************************************************************************/
__M_PAGE(Author,"AUTHOR",&Homepage,
{
	SOLGUI_Widget_OptionText(0,"COMPANY:   505_Tech");
	SOLGUI_Widget_OptionText(1,"QQ:      2843067579");
});
/*===========================新建菜单页面格式及常用函数=============================
__M_PAGE(name(),pageTitle,parentPage,
//（该页面名称，“页面标题”，&上级页面名）
{

    SOLGUI_Cursor( uint8_t rowBorder_Top, uint8_t rowBorder_Bottom, uint8_t option_num)
    //（上边界行，下边界行，选项个数）

    页面跳转控件:
    SOLGUI_Widget_GotoPage( uint8_t USN,MENU_PAGE *page)
    //(该选项所处位置,	&页面地址)

    按键控件：
    SOLGUI_Widget_Button( uint8_t USN,const  uint8_t *name,void (*func)(void))
    //(该选项所处位置,"该选项显示的文字",&按下该按键时执行的无参数void类型函数);

    数字旋钮控件：
    SOLGUI_Widget_Spin( uint8_t USN,const  uint8_t *name, uint8_t type,double max,double min,void* value)
    //(该选项所处位置,"该选项显示的文字",变量类型（如INT32）,变化上限,变化下限,&变量地址);

    自由文本控件：
    SOLGUI_Widget_Text( uint32_t x0, uint32_t y0, uint8_t mode,const  uint8_t* str,...)
    //(横坐标,纵坐标,字号（如F4X6）,"需要显示的文字（格式同printf）",用法同printf字符串后的参数);

});
================================================================================*/
///////////////////////////////////////////////////////////////////-=505-Tech=-///
