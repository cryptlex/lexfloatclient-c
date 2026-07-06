Imports Cryptlex

Public Class Form1

    Public Sub New()
        InitializeComponent()
    End Sub

    Private Sub LicenceRenewCallback(ByVal status As UInteger)
        Select Case status
            Case LexFloatStatusCodes.LF_OK
                Me.statusLabel.Text = "The license lease has renewed successfully."
                Exit Select
            Case LexFloatStatusCodes.LF_E_LICENSE_NOT_FOUND
                Me.statusLabel.Text = "The license expired before it could be renewed."
                Exit Select
            Case LexFloatStatusCodes.LF_E_LICENSE_EXPIRED_INET
                Me.statusLabel.Text = "The license expired due to network connection failure."
                Exit Select
            Case Else
                Me.statusLabel.Text = "The license renew failed due to other reason. Error code: " & status.ToString()
                Exit Select
        End Select
    End Sub

    Private Sub leaseBtn_Click(sender As Object, e As EventArgs) Handles leaseBtn.Click

        Try
            LexFloatClient.SetHostProductId("PASTE_YOUR_PRODUCT_ID")
            LexFloatClient.SetHostUrl("http://localhost:8090")
            LexFloatClient.SetFloatingLicenseCallback(AddressOf LicenceRenewCallback)
            LexFloatClient.RequestFloatingLicense()
            Me.statusLabel.Text = "License leased successfully!"
        Catch ex As LexFloatClientException
            Me.statusLabel.Text = "Error code: " & ex.Code.ToString() & " Error message: " + ex.Message
        End Try
    End Sub

    Private Sub dropBtn_Click(sender As Object, e As EventArgs) Handles dropBtn.Click
        Try
            If Not LexFloatClient.HasFloatingLicense() Then
                Return
            End If

            LexFloatClient.DropFloatingLicense()
            Me.statusLabel.Text = "License dropped successfully!"
        Catch ex As LexFloatClientException
            Me.statusLabel.Text = "Error code: " & ex.Code.ToString() & " Error message: " + ex.Message
        End Try
    End Sub
End Class
