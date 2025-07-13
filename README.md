# Hemy Markdown Editor Power by Qt

## 菜单栏定义模板

```xml
<Menu>
    <menuItem type="menu"> <!-- type: 支持menu、action、separator-->
        <Label>标签</Label> <!-- 显示在菜单上的字符 -->
        <Url>Http链接</Url> <!-- 点击菜单项跳转到对应的链接，menu类型的不支持该属性 -->
        <ObjName>对象名称</ObjName>
        <ShortCut>快捷键</ShortCut>
        <QmlFile>关联的Qml文件路径</QmlFile>
        <Icon>图标</Icon>
        <!-- 子菜单同样是 menuItem -->
        <menuItem type="action"> <!-- type: 支持menu、action、separator-->
            <ObjName>action对象名称</ObjName>
            <Label>子菜单项名称</Label>
            <Url>如果是Http链接，可以带url参数</Url>
            <ShortCut>快捷键</ShortCut>
            <QmlFile>关联的Qml文件路径</QmlFile>
            <Icon>图标</Icon>
        </menuItem>
    </menuItem>
    <menuItem type="separator"/> <!-- 菜单项分割线 -->
    <menuItem type="action">
        <ObjName>action对象名称</ObjName>
        <Label>菜单项名称</Label>
        <Url>如果是Http链接，可以带url参数</Url>
        <ShortCut>快捷键</ShortCut>
        <QmlFile>关联的Qml文件路径</QmlFile>
        <Icon>图标</Icon></menuItem>
</Menu>
```