Public Class Form1

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

    End Sub
    
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        ejecutar_comando(con, "INSERT INTO PROVINCIAS VALUES('" & TextBox1.Text & "','" & TextBox2.Text & "')")
    End Sub
End Class
