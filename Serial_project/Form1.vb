Imports System
Imports System.Threading
Imports System.IO
Imports System.ComponentModel

Public Class Form1
    Dim myPort As Array
    Delegate Function recieveData() As String
    Delegate Function same(ByVal x As Integer, ByVal y As Integer) As Boolean
    Function equalto(ByVal x As Integer, ByVal y As Integer) As Boolean
        If x = y Then
            Return True
        Else : Return False
        End If
    End Function

    Function ReceiveSerialData() As String
        ' Receive strings from a serial port. 
        Dim returnStr As String = ""

        Dim com1 As IO.Ports.SerialPort = Nothing
        Try
            com1 = My.Computer.Ports.OpenSerialPort("COM3")
            com1.ReadTimeout = 10000
            Do
                Dim Incoming As String = com1.ReadLine()
                If Incoming Is Nothing Then
                    Exit Do
                Else
                    returnStr &= Incoming & vbCrLf
                End If
            Loop
        Catch ex As TimeoutException
            returnStr = "Error: Serial Port read timed out."
        Finally
            If com1 IsNot Nothing Then com1.Close()
        End Try

        Return returnStr
    End Function

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        myPort = IO.Ports.SerialPort.GetPortNames()
        PortComboBox.Items.AddRange(myPort)
    End Sub

    Private Sub RichTextBox1_TextChanged(sender As Object, e As EventArgs)

    End Sub

    Private Sub Button1_Click_1(sender As Object, e As EventArgs) Handles Readbutton.Click
        SerialPort1.PortName = PortComboBox.Text                    'ianuragit
        SerialPort1.BaudRate = BaudComboBox.Text
        SerialPort1.Open()
        Readbutton.Enabled = True
        CloseButton.Enabled = True
        Dim rsd As recieveData = AddressOf Me.ReceiveSerialData
        Dim res As String = rsd.Invoke()
        RichTextBox1.Text = res


    End Sub

    Private Sub CloseButton_Click(sender As Object, e As EventArgs) Handles CloseButton.Click
        Readbutton.Enabled = False
        CloseButton.Enabled = False

    End Sub

    Private Sub OpenFileDialog1_FileOk(sender As Object, e As CancelEventArgs) Handles OpenFileDialog1.FileOk

    End Sub
End Class
